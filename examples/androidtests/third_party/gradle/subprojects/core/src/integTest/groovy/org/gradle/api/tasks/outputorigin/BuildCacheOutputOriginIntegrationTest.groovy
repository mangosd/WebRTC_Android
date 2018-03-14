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

package org.gradle.api.tasks.outputorigin

import org.gradle.integtests.fixtures.AbstractIntegrationSpec
import org.gradle.integtests.fixtures.DirectoryBuildCacheFixture
import org.gradle.integtests.fixtures.ScopeIdsFixture
import org.gradle.integtests.fixtures.TaskOutputOriginBuildInvocationIdFixture
import org.gradle.internal.id.UniqueId
import org.junit.Rule

class BuildCacheOutputOriginIntegrationTest extends AbstractIntegrationSpec implements DirectoryBuildCacheFixture {

    @Rule
    public final ScopeIdsFixture scopeIds = new ScopeIdsFixture(executer, temporaryFolder)

    @Rule
    public final TaskOutputOriginBuildInvocationIdFixture originBuildInvocationId = new TaskOutputOriginBuildInvocationIdFixture(executer, temporaryFolder)

    UniqueId getBuildInvocationId() {
        scopeIds.buildInvocationId
    }

    UniqueId originBuildInvocationId(String taskPath) {
        originBuildInvocationId.originId(taskPath)
    }

    def setup() {
        executer.beforeExecute {
            it.withBuildCacheEnabled()
        }
    }

    def "exposes origin build id when reusing cached outputs"() {
        given:
        buildScript """
            apply plugin: "base"
            def write = tasks.create("write", WriteProperties) {
                outputFile = "build/out.properties"
                properties = [v: 1]
            }
        """

        when:
        succeeds "write"

        then:
        executedAndNotSkipped ":write"
        def firstBuildId = buildInvocationId
        originBuildInvocationId(":write") == null

        when:
        succeeds "clean", "write"

        then:
        executed ":write"
        def secondBuildId = buildInvocationId
        firstBuildId != secondBuildId
        originBuildInvocationId(":write") == firstBuildId

        when:
        buildFile << """
            write.property("changed", "now")
        """
        succeeds "clean", "write"

        then:
        executedAndNotSkipped ":write"
        def thirdBuildId = buildInvocationId
        firstBuildId != thirdBuildId
        secondBuildId != thirdBuildId
        originBuildInvocationId(":write") == null

        when:
        succeeds "clean", "write"

        then:
        executed ":write"
        originBuildInvocationId(":write") == thirdBuildId
    }

}
