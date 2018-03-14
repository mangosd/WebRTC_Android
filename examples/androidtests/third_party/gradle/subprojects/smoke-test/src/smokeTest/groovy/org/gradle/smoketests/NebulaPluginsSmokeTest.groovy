/*
 * Copyright 2016 the original author or authors.
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

package org.gradle.smoketests

import spock.lang.Issue

class NebulaPluginsSmokeTest extends AbstractSmokeTest {

    @Issue('https://plugins.gradle.org/plugin/nebula.dependency-recommender')
    def 'nebula recommender plugin'() {
        when:
        buildFile << """
            plugins {
                id "java"
                id "nebula.dependency-recommender" version "5.0.0"
            }

            ${jcenterRepository()}

            dependencyRecommendations {
                mavenBom module: 'netflix:platform:latest.release'
            }

            dependencies {
                compile 'com.google.guava:guava' // no version, version is recommended
                compile 'commons-lang:commons-lang:2.6' // I know what I want, don't recommend
            }
            """

        then:
        runner('build').build()
    }

    @Issue('https://plugins.gradle.org/plugin/nebula.plugin-plugin')
    def 'nebula plugin plugin'() {
        when:
        buildFile << """
            plugins {
                id 'nebula.plugin-plugin' version '5.17.2'
            }
        """

        file("src/main/groovy/pkg/Thing.java") << """
            package pkg;

            import java.util.ArrayList;
            import java.util.List;

            public class Thing {
                private List<String> firstOrderDepsWithoutVersions = new ArrayList<>();
            }
        """

        then:
        runner('groovydoc').build()
    }

    @Issue('https://plugins.gradle.org/plugin/nebula.lint')
    def 'nebula lint plugin'() {
        given:
        buildFile << """
            buildscript {
                ${jcenterRepository()}
            }

            plugins {
                id "nebula.lint" version "8.3.1"
            }

            apply plugin: 'java'

            gradleLint.rules = ['dependency-parentheses']

            dependencies {
                testCompile('junit:junit:4.7')
            }
        """.stripIndent()

        when:
        def result = runner('autoLintGradle').build()

        then:
        int numOfRepoBlockLines = 14 + jcenterRepository().readLines().size()
        result.output.contains("parentheses are unnecessary for dependencies")
        result.output.contains("warning   dependency-parentheses")
        result.output.contains("build.gradle:$numOfRepoBlockLines")
        result.output.contains("testCompile('junit:junit:4.7')")
        buildFile.text.contains("testCompile('junit:junit:4.7')")

        when:
        result = runner('fixGradleLint').build()

        then:
        result.output.contains("""fixed          dependency-parentheses             parentheses are unnecessary for dependencies
build.gradle:$numOfRepoBlockLines
testCompile('junit:junit:4.7')""")
        buildFile.text.contains("testCompile 'junit:junit:4.7'")
    }

    @Issue('https://plugins.gradle.org/plugin/nebula.dependency-lock')
    def 'nebula dependency lock plugin'() {
        when:
        buildFile << """
            plugins {
                id "nebula.dependency-lock" version "4.9.5"
            }
        """.stripIndent()

        then:
        runner('buildEnvironment', 'generateLock').build()
    }
}
