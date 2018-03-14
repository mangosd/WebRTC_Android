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

package org.gradle.language.swift.plugins

import org.gradle.integtests.fixtures.WellBehavedPluginTest
import org.gradle.nativeplatform.fixtures.AvailableToolChains
import org.gradle.util.Requires
import org.gradle.util.TestPrecondition

// JDK8_OR_EARLIER: Since InstalledToolChain#initialiseEnvironment() modify the process's environment variables,
// the tests won't work properly on JDK 9. By refactoring the tests, it would be possible to work around this
// limitation.
@Requires([TestPrecondition.SWIFT_SUPPORT, TestPrecondition.JDK8_OR_EARLIER])
abstract class AbstractSwiftPluginIntegrationTest extends WellBehavedPluginTest {
    AvailableToolChains.InstalledToolChain toolChain

    def setup() {
        toolChain = AvailableToolChains.findSwiftc()
        if (toolChain.isAvailable()) {
            toolChain.initialiseEnvironment()
        }
    }

    def cleanup() {
        if (toolChain.isAvailable()) {
            toolChain.resetEnvironment()
        }
    }
}
