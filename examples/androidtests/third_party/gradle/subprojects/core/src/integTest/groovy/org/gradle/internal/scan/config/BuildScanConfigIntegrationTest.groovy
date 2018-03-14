/*
 * Copyright 2017 the original author or authors.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package org.gradle.internal.scan.config

import org.gradle.integtests.fixtures.AbstractIntegrationSpec
import org.gradle.test.fixtures.plugin.PluginBuilder
import spock.lang.Unroll

import static org.gradle.plugin.management.internal.autoapply.DefaultAutoAppliedPluginRegistry.BUILD_SCAN_PLUGIN_AUTO_APPLY_VERSION

@Unroll
class BuildScanConfigIntegrationTest extends AbstractIntegrationSpec {

    private static final String PLUGIN_NOT_APPLIED_MSG = """Build scan cannot be created because the build scan plugin was not applied.
For more information on how to apply the build scan plugin, please visit https://gradle.com/scans/help/gradle-cli."""
    public static final String VERSION_CHECK_FAIL_MSG = """This version of Gradle requires version 1.8.0 of the build scan plugin or later.
Please see https://gradle.com/scans/help/gradle-incompatible-plugin-version for more information."""

    boolean collect = true
    String pluginVersionNumber = "2.0"

    def setup() {
        publishDummyBuildScanPlugin(BUILD_SCAN_PLUGIN_AUTO_APPLY_VERSION)

        executer.beforeExecute {
            if (collect) {
                buildScript """
                    def c = services.get(${BuildScanConfigProvider.name}).collect([getVersion: { "$pluginVersionNumber" }] as $BuildScanPluginMetadata.name) 
                    println "buildScan.enabled: " + c.enabled 
                    println "buildScan.disabled: " + c.disabled 
                """
            }

            buildFile << """    
                def pluginApplied = services.get(${BuildScanPluginApplied.name}).isBuildScanPluginApplied()
                println "buildScan plugin applied: " + pluginApplied
            """

            buildFile << "task t"
        }
    }

    private void publishDummyBuildScanPlugin(String version) {
        settingsFile << """
            pluginManagement {
                repositories {
                    maven { url '${mavenRepo.uri}' }
                }
            }
"""
        def builder = new PluginBuilder(testDirectory.file('plugin-' + version))
        builder.addPlugin("", "com.gradle.build-scan", "DummyBuildScanPlugin")
        builder.publishAs("com.gradle:build-scan-plugin:${version}", mavenRepo, executer)
    }

    def "enabled and disabled are false with no flags"() {
        when:
        succeeds "t"

        then:
        output.contains("buildScan.enabled: false")
        output.contains("buildScan.disabled: false")
    }

    def "enabled with --scan"() {
        when:
        succeeds "t", "--scan"

        then:
        output.contains("buildScan.enabled: true")
        output.contains("buildScan.disabled: false")
    }

    def "disabled with --no-scan"() {
        when:
        succeeds "t", "--no-scan"

        then:
        output.contains("buildScan.enabled: false")
        output.contains("buildScan.disabled: true")
    }

    def "not enabled with -Dscan"() {
        // build scan plugin will treat this as enabled
        when:
        succeeds "t", "-Dscan"

        then:
        output.contains("buildScan.enabled: false")
        output.contains("buildScan.disabled: false")
    }

    def "not disabled with -Dscan=false"() {
        when:
        succeeds "t", "-Dscan=false"

        then:
        output.contains("buildScan.enabled: false")
        output.contains("buildScan.disabled: false")
    }

    def "warns if scan requested but no scan plugin applied"() {
        given:
        collect = false

        when:
        succeeds "t", "--scan"

        then:
        issuedNoPluginWarning()
    }

    def "warns if scan requested by sys prop value #value but no scan plugin applied"() {
        given:
        collect = false

        when:
        succeeds "t", value == null ? "-Dscan" : "-Dscan=$value"

        then:
        issuedNoPluginWarning()

        where:
        value << [null, "", "true", "yes"]
    }

    def "does not warn if no scan requested but no scan plugin applied"() {
        given:
        collect = false

        when:
        succeeds "t", "--no-scan"

        then:
        !issuedNoPluginWarning()
    }

    def "fails if plugin is too old"() {
        given:
        pluginVersionNumber = "1.7.4"

        when:
        fails "t", "--scan"

        then:
        assertFailedVersionCheck()

        when:
        fails "t", "--no-scan"

        then:
        assertFailedVersionCheck()

        when:
        fails "t"

        then:
        assertFailedVersionCheck()
    }

    def "does not warn for each nested build if --scan used"() {
        given:
        collect = false
        file("buildSrc/build.gradle") << ""
        file("a/buildSrc/build.gradle") << ""
        file("a/build.gradle") << ""
        file("a/settings.gradle") << ""
        file("b/buildSrc/build.gradle") << ""
        file("b/build.gradle") << ""
        file("b/settings.gradle") << ""
        settingsFile << """
            includeBuild "a"
            includeBuild "b"
        """

        when:
        succeeds "--scan"

        then:
        output.count(PLUGIN_NOT_APPLIED_MSG) == 1
    }

    def "detects that the build scan plugin has been #description"() {
        given:
        collect = applied

        when:
        succeeds "t"

        then:
        output.contains("buildScan plugin applied: ${applied}")

        where:
        applied << [true, false]
        description = applied ? "applied" : "not applied"
    }

    void assertFailedVersionCheck() {
        failureHasCause VERSION_CHECK_FAIL_MSG
    }

    boolean issuedNoPluginWarning() {
        output.contains PLUGIN_NOT_APPLIED_MSG
    }

}
