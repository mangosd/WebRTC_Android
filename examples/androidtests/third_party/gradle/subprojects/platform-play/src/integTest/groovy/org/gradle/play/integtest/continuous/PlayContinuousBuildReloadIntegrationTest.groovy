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

package org.gradle.play.integtest.continuous

import org.gradle.internal.filewatch.PendingChangesManager
import org.gradle.test.fixtures.ConcurrentTestUtil

/**
 * Test Play reload with `--continuous`
 */
class PlayContinuousBuildReloadIntegrationTest extends AbstractPlayReloadIntegrationTest {

    int pendingChangesMarker

    def setup() {
        buildFile << """
                def pendingChangesManager = gradle.services.get(${PendingChangesManager.canonicalName})
                pendingChangesManager.addListener {
                    println "Pending changes detected"
                }
        """
    }

    private int waitForChangesToBePickedUp() {
        def buildOutput = ''
        ConcurrentTestUtil.poll {
            buildOutput = buildOutputSoFar()
            assert buildOutput.substring(pendingChangesMarker).contains("Pending changes detected")
        }
        pendingChangesMarker = buildOutput.length()
    }

    def "should reload modified scala controller and routes"() {
        when:
        succeeds("runPlayBinary")

        then:
        appIsRunningAndDeployed()

        when:
        addNewRoute('hello')
        waitForChangesToBePickedUp()

        then:
        runningApp.playUrl('hello').text == 'hello world'
    }

    def "should reload with exception when modify scala controller"() {
        when:
        succeeds("runPlayBinary")
        then:
        appIsRunningAndDeployed()

        when:
        addBadCode()
        waitForChangesToBePickedUp()

        then:
        println "CHECKING ERROR PAGE"
        errorPageHasTaskFailure("compilePlayBinaryScala")
        !executedTasks.contains('runPlayBinary')

        when:
        fixBadCode()
        waitForChangesToBePickedUp()
        println "CHANGES DETECTED IN BUILD"

        then:
        appIsRunningAndDeployed()
    }

    def "should reload modified coffeescript"() {
        when:
        succeeds("runPlayBinary")

        then:
        appIsRunningAndDeployed()
        !runningApp.playUrl('assets/javascripts/test.js').text.contains('Hello coffeescript')
        !runningApp.playUrl('assets/javascripts/test.min.js').text.contains('Hello coffeescript')

        when:
        file("app/assets/javascripts/test.coffee") << '''
message = "Hello coffeescript"
alert message
'''
        waitForChangesToBePickedUp()

        then:
        runningApp.playUrl('assets/javascripts/test.js').text.contains('Hello coffeescript')
        runningApp.playUrl('assets/javascripts/test.min.js').text.contains('Hello coffeescript')
    }

    def "should detect new javascript files"() {
        when:
        succeeds("runPlayBinary")

        then:
        appIsRunningAndDeployed()

        when:
        file("app/assets/javascripts/helloworld.js") << '''
var message = "Hello JS";
'''
        waitForChangesToBePickedUp()

        then:
        runningApp.playUrl('assets/javascripts/helloworld.js').text.contains('Hello JS')
        runningApp.playUrl('assets/javascripts/helloworld.min.js').text.contains('Hello JS')
    }

    def "should reload modified java model"() {
        when:
        succeeds("runPlayBinary")

        then:
        appIsRunningAndDeployed()
        assert runningApp.playUrl().text.contains("<li>foo:1</li>")

        when:
        file("app/models/DataType.java").with {
            text = text.replaceFirst(~/"%s:%s"/, '"Hello %s:%s !"')
        }
        waitForChangesToBePickedUp()

        then:
        runningApp.playUrl().text.contains("<li>Hello foo:1 !</li>")
    }

    def "should reload twirl template"() {
        when:
        succeeds("runPlayBinary")

        then:
        appIsRunningAndDeployed()

        when:
        file("app/views/index.scala.html").with {
            text = text.replaceFirst(~/Welcome to Play/, 'Welcome to Play with Gradle')
        }
        waitForChangesToBePickedUp()

        then:
        runningApp.playUrl().text.contains("Welcome to Play with Gradle")
    }

    def "should reload with exception when task that depends on runPlayBinary fails"() {
        given:
        buildFile << """
task otherTask {
   dependsOn 'runPlayBinary'
   doLast {
      // second time through this route exists
      if (file("conf/routes").text.contains("/hello")) {
         throw new GradleException("always fails")
      }
   }
}
"""
        when:
        succeeds("otherTask")
        then:
        appIsRunningAndDeployed()

        when:
        addNewRoute('hello')
        waitForChangesToBePickedUp()

        then:
        errorPageHasTaskFailure("otherTask")
        !executedTasks.contains('runPlayBinary')
    }
}
