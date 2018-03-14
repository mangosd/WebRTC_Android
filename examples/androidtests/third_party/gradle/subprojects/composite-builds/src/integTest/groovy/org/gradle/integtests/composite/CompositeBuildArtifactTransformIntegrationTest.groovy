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

package org.gradle.integtests.composite

class CompositeBuildArtifactTransformIntegrationTest extends AbstractCompositeBuildIntegrationTest {
    def "can apply a transform to the outputs of included builds"() {
        def buildB = singleProjectBuild("buildB") {
            buildFile << """
                apply plugin: 'java'
            """
        }
        def buildC = singleProjectBuild("buildC") {
            buildFile << """
                apply plugin: 'java'
            """
        }
        includedBuilds << buildB
        includedBuilds << buildC

        buildA.buildFile << """
            class XForm extends ArtifactTransform {
                List<File> transform(File file) {
                    return [file]
                }
            }
            
            dependencies {
                compile 'org.test:buildB:1.2'
                compile 'org.test:buildC:1.2'
                
                registerTransform {
                    from.attribute(Attribute.of("artifactType", String), "jar")
                    to.attribute(Attribute.of("artifactType", String), "xform")
                    artifactTransform(XForm)
                }
            }
        """
        expect:
        execute(buildA, "assemble")
        assertTaskExecuted(":buildB", ":jar")
        assertTaskExecuted(":buildC", ":jar")
    }
}
