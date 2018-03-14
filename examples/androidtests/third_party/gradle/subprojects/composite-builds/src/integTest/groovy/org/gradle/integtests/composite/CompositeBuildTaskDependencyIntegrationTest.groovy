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

package org.gradle.integtests.composite

import org.gradle.integtests.fixtures.build.BuildTestFile
import spock.lang.Unroll

/**
 * Tests for composite build delegating to tasks in an included build.
 */
class CompositeBuildTaskDependencyIntegrationTest extends AbstractCompositeBuildIntegrationTest {
    BuildTestFile buildB

    def setup() {
        buildB = multiProjectBuild("buildB", ['b1', 'b2']) {
            buildFile << """
                allprojects {
                    task logProject {
                        doLast {
                            println "Executing build '" + project.rootProject.name + "' project '" + project.path + "' task '" + path + "'"
                        }
                    }
                }
"""
        }
        includedBuilds << buildB
    }

    def "can depend on task in root project of included build"() {
        when:
        buildA.buildFile << """
    task delegate {
        dependsOn gradle.includedBuild('buildB').task(':logProject')
    }
"""

        execute(buildA, ":delegate")

        then:
        executed ":buildB:logProject"
        output.contains("Executing build 'buildB' project ':' task ':logProject'")
    }

    def "can depend on task in subproject of included build"() {
        when:
        buildA.buildFile << """
    task delegate {
        dependsOn gradle.includedBuild('buildB').task(':b1:logProject')
    }
"""

        execute(buildA, ":delegate")

        then:
        executed ":buildB:b1:logProject"
        output.contains("Executing build 'buildB' project ':b1' task ':b1:logProject'")
    }

    def "can depend on multiple tasks of included build"() {
        when:
        buildA.buildFile << """
    def buildB = gradle.includedBuild('buildB')
    task delegate {
        dependsOn 'delegate1', 'delegate2'
    }

    task delegate1 {
        dependsOn buildB.task(':logProject')
        dependsOn buildB.task(':b1:logProject')
    }

    task delegate2 {
        dependsOn buildB.task(':logProject')
    }
"""

        execute(buildA, ":delegate")

        then:
        executed ":buildB:logProject", ":buildB:b1:logProject"
        output.contains("Executing build 'buildB' project ':' task ':logProject'")
        output.contains("Executing build 'buildB' project ':b1' task ':b1:logProject'")
    }

    def "executes tasks only once for included build"() {
        when:
        buildA.buildFile << """
    def buildB = gradle.includedBuild('buildB')
    task delegate {
        dependsOn buildB.task(':b1:logProject')
        dependsOn buildB.task(':b2:logProject')
    }
"""
        buildB.buildFile << """
    project(":b1") {
        logProject.dependsOn(':b2:logProject')
    }
"""

        execute(buildA, ":delegate")

        then:
        executed ":buildB:b2:logProject", ":buildB:b1:logProject"
        output.contains("Executing build 'buildB' project ':b2' task ':b2:logProject'")
        output.contains("Executing build 'buildB' project ':b1' task ':b1:logProject'")
    }

    def "can depend on task from subproject of composing build"() {
        given:
        buildA.settingsFile << """
    include 'a1'
"""
        buildA.buildFile << """
    task("top-level") {
        dependsOn ':a1:delegate'
    }

    project(':a1') {
        task delegate {
            dependsOn gradle.includedBuild('buildB').task(':logProject')
        }
    }
"""

        when:
        execute(buildA, ":top-level")

        then:
        executed ":buildB:logProject"
        output.contains("Executing build 'buildB' project ':' task ':logProject'")

        when:
        execute(buildA, "delegate")

        then:
        executed ":buildB:logProject"
        output.contains("Executing build 'buildB' project ':' task ':logProject'")
    }

    def "can depend on task with name in all included builds"() {
        when:
        BuildTestFile buildC = singleProjectBuild("buildC") {
            buildFile.text = buildB.buildFile.text
        }
        includedBuilds << buildC

        buildA.buildFile << """
    task delegate {
        dependsOn gradle.includedBuilds*.task(':logProject')
    }
"""

        execute(buildA, ":delegate")

        then:
        executed ":buildB:logProject", ":buildC:logProject"
        output.contains("Executing build 'buildB' project ':' task ':logProject'")
        output.contains("Executing build 'buildC' project ':' task ':logProject'")
    }

    def "substitutes dependency of included build when executed via task dependency"() {
        given:
        buildA.buildFile << """
    task delegate {
        dependsOn gradle.includedBuild('buildB').task(':jar')
    }
"""
        buildB.buildFile << """
    allprojects {
        apply plugin: 'java'
    }

    dependencies {
        compile "org.test:b1:1.0"
    }
"""

        when:
        execute(buildA, ":delegate")

        then:
        executed ":buildB:b1:jar", ":buildB:jar"
    }

    def "reports failure when included build does not exist for composite"() {
        when:
        buildA.buildFile << """
    task delegate {
        dependsOn gradle.includedBuild('does-not-exist').task(':anything')
    }
"""

        and:
        fails(buildA, ":delegate")

        then:
        failure.assertHasDescription("A problem occurred evaluating root project 'buildA'.")
        failure.assertHasCause("Included build 'does-not-exist' not found.")
    }

    def "reports failure when task does not exist for included build"() {
        when:
        buildA.buildFile << """
    task delegate {
        dependsOn gradle.includedBuild('buildB').task(':does-not-exist')
    }
"""

        and:
        fails(buildA, ":delegate")

        then:
        failure.assertHasDescription("Task 'does-not-exist' not found in project ':buildB'.")
    }

    def "reports failure when task path is not qualified for included build"() {
        when:
        buildA.buildFile << """
    task delegate {
        dependsOn gradle.includedBuild('buildB').task('logProject')
    }
"""

        and:
        fails(buildA, "delegate")

        then:
        failure.assertHasDescription("A problem occurred evaluating root project 'buildA'.")
        failure.assertHasCause("Task path 'logProject' is not a qualified task path (e.g. ':task' or ':project:task')")
    }

    def "reports failure when task path is substring of task in included build"() {
        given:
        buildA.buildFile << """
    task delegate {
        dependsOn gradle.includedBuild('buildB').task(':logP')
    }
    task subDelegate {
        dependsOn gradle.includedBuild('buildB').task(':b1:logP')
    }
"""

        when:
        fails(buildA, ":delegate")

        then:
        failure.assertHasDescription("Task ':logP' not found in build 'buildB'.")

        when:
        fails(buildA, ":subDelegate")

        then:
        failure.assertHasDescription("Task ':b1:logP' not found in build 'buildB'.")
    }

    def "reports failure when attempting to access included build when build is not a composite"() {
        when:
        buildB.buildFile << """
    task delegate {
        dependsOn gradle.includedBuild('does-not-exist').task(':anything')
    }
"""

        and:
        fails(buildB, ":delegate")

        then:
        failure.assertHasDescription("A problem occurred evaluating root project 'buildB'.")
        failure.assertHasCause("Included build 'does-not-exist' not found.")
    }

    def "reports failure when delegating to included build when composing build defines a task with the same name as the included build"() {
        when:
        buildA.buildFile << """
    task _buildB_logProject // Just a regular old task instance
    task delegate {
        dependsOn gradle.includedBuild('buildB').task(':logProject')
    }
"""

        and:
        fails(buildA, ":delegate")

        then:
        failure.assertHasDescription("Could not determine the dependencies of task ':delegate'.")
        failure.assertHasCause("Cannot create delegating task '_buildB_logProject' as task with same name already exists.")
    }

    @Unroll
    def "included build cannot reference tasks in #scenario"() {
        when:
        BuildTestFile buildC = singleProjectBuild("buildC") {
            buildFile << """
    task illegal {
        dependsOn gradle.includedBuild('$buildName').task(':logProject')
    }
"""
        }
        includedBuilds << buildC

        buildA.buildFile << """
    task delegate {
        dependsOn gradle.includedBuild('buildC').task(':illegal')
    }
    task logProject {}
"""

        then:
        fails(buildA, ":delegate")

        and:
        failure.assertHasDescription("A problem occurred evaluating project ':buildC'.")
        failure.assertHasCause("Included build '${buildName}' not found.")

        where:
        scenario  | buildName
        "sibling" | "buildB"
        "parent"  | "buildA"
    }
}
