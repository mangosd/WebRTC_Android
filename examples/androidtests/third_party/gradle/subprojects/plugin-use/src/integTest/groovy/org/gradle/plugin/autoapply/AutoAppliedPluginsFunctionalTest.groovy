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

package org.gradle.plugin.autoapply

import org.gradle.integtests.fixtures.AbstractIntegrationSpec
import org.gradle.integtests.fixtures.executer.GradleHandle
import org.gradle.test.fixtures.file.LeaksFileHandles
import org.gradle.util.Requires
import org.gradle.util.TestPrecondition

import static org.gradle.integtests.fixtures.BuildScanUserInputFixture.*

@Requires(TestPrecondition.ONLINE)
@LeaksFileHandles
class AutoAppliedPluginsFunctionalTest extends AbstractIntegrationSpec {

    private static final String BUILD_SCAN_LICENSE_QUESTION = 'Do you accept the Gradle Cloud Services license agreement (https://gradle.com/terms-of-service)? [yes, no]'
    private static final String BUILD_SCAN_SUCCESSFUL_PUBLISHING = 'Publishing build scan'
    private static final String BUILD_SCAN_PLUGIN_CONFIG_PROBLEM = 'The build scan was not published due to a configuration problem.'
    private static final String BUILD_SCAN_LICENSE_NOTE = 'The Gradle Cloud Services license agreement has not been agreed to.'
    private static final String BUILD_SCAN_LICENSE_ACCEPTANCE = 'Gradle Cloud Services license agreement accepted.'
    private static final String BUILD_SCAN_LICENSE_DECLINATION = 'Gradle Cloud Services license agreement not accepted.'

    def setup() {
        requireOwnGradleUserHomeDir()
        requireGradleDistribution()
    }

    def "can auto-apply build scan plugin but does not ask for license acceptance in non-interactive console"() {
        given:
        buildFile << dummyBuildFile()

        when:
        def gradleHandle = startBuildWithBuildScanCommandLineOption()

        then:
        def result = gradleHandle.waitForFinish()
        !result.output.contains(BUILD_SCAN_LICENSE_QUESTION)
        result.output.contains(BUILD_SCAN_PLUGIN_CONFIG_PROBLEM)
        result.output.contains(BUILD_SCAN_LICENSE_NOTE)
        !result.output.contains(BUILD_SCAN_SUCCESSFUL_PUBLISHING)
    }

    def "can auto-apply build scan plugin and accept license in interactive console"() {
        given:
        withInteractiveConsole()
        buildFile << dummyBuildFile()

        when:
        def gradleHandle = startBuildWithBuildScanCommandLineOption()

        then:
        writeToStdInAndClose(gradleHandle, YES.bytes)
        def result = gradleHandle.waitForFinish()
        result.output.contains(BUILD_SCAN_LICENSE_QUESTION)
        result.output.contains(BUILD_SCAN_LICENSE_ACCEPTANCE)
        result.output.contains(BUILD_SCAN_SUCCESSFUL_PUBLISHING)
        !result.output.contains(BUILD_SCAN_PLUGIN_CONFIG_PROBLEM)
        !result.output.contains(BUILD_SCAN_LICENSE_NOTE)
    }

    def "can auto-apply build scan plugin and decline license in interactive console"() {
        given:
        withInteractiveConsole()
        buildFile << dummyBuildFile()

        when:
        def gradleHandle = startBuildWithBuildScanCommandLineOption()

        then:
        writeToStdInAndClose(gradleHandle, NO.bytes)
        def result = gradleHandle.waitForFinish()
        result.output.contains(BUILD_SCAN_LICENSE_QUESTION)
        result.output.contains(BUILD_SCAN_LICENSE_DECLINATION)
        result.output.contains(BUILD_SCAN_PLUGIN_CONFIG_PROBLEM)
        !result.output.contains(BUILD_SCAN_SUCCESSFUL_PUBLISHING)
        result.output.contains(BUILD_SCAN_PLUGIN_CONFIG_PROBLEM)
        !result.output.contains(BUILD_SCAN_LICENSE_NOTE)
        result.output.contains("The buildScan extension 'licenseAgree' value must be exactly the string 'yes' (without quotes).")
        result.output.contains("The value given was 'no'.")
    }

    def "can auto-apply build scan plugin and cancel license acceptance with ctrl-d in interactive console"() {
        given:
        withInteractiveConsole()
        buildFile << dummyBuildFile()

        when:
        def gradleHandle = startBuildWithBuildScanCommandLineOption()

        then:
        writeToStdInAndClose(gradleHandle, EOF)
        def result = gradleHandle.waitForFinish()
        result.output.contains(BUILD_SCAN_LICENSE_QUESTION)
        !result.output.contains(BUILD_SCAN_LICENSE_ACCEPTANCE)
        !result.output.contains(BUILD_SCAN_LICENSE_DECLINATION)
        result.output.contains(BUILD_SCAN_PLUGIN_CONFIG_PROBLEM)
        result.output.contains(BUILD_SCAN_LICENSE_NOTE)
        !result.output.contains(BUILD_SCAN_SUCCESSFUL_PUBLISHING)
    }

    private void withInteractiveConsole() {
        executer.withStdinPipe().withForceInteractive(true)
    }

    private GradleHandle startBuildWithBuildScanCommandLineOption() {
        return executer.withTasks(DUMMY_TASK_NAME).withArgument('--scan').start()
    }

    static String dummyBuildFile() {
        "task $DUMMY_TASK_NAME"
    }
}
