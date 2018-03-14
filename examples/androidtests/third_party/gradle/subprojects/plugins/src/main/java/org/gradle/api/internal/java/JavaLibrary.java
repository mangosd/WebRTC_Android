/*
 * Copyright 2012 the original author or authors.
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

package org.gradle.api.internal.java;

import com.google.common.collect.ImmutableSet;
import org.gradle.api.artifacts.ConfigurationContainer;
import org.gradle.api.artifacts.DependencySet;
import org.gradle.api.artifacts.ModuleDependency;
import org.gradle.api.artifacts.PublishArtifact;
import org.gradle.api.attributes.Usage;
import org.gradle.api.internal.component.SoftwareComponentInternal;
import org.gradle.api.internal.component.UsageContext;
import org.gradle.api.internal.model.DefaultObjectFactory;
import org.gradle.api.internal.model.NamedObjectInstantiator;
import org.gradle.api.model.ObjectFactory;
import org.gradle.internal.reflect.DirectInstantiator;

import java.util.Collections;
import java.util.LinkedHashSet;
import java.util.Set;

import static org.gradle.api.plugins.JavaPlugin.API_ELEMENTS_CONFIGURATION_NAME;
import static org.gradle.api.plugins.JavaPlugin.RUNTIME_ELEMENTS_CONFIGURATION_NAME;

/**
 * A SoftwareComponent representing a library that runs on a java virtual machine.
 */
public class JavaLibrary implements SoftwareComponentInternal {

    // This must ONLY be used in the deprecated constructor, for backwards compatibility
    private final static ObjectFactory DEPRECATED_OBJECT_FACTORY = new DefaultObjectFactory(DirectInstantiator.INSTANCE, NamedObjectInstantiator.INSTANCE);

    private final LinkedHashSet<PublishArtifact> artifacts = new LinkedHashSet<PublishArtifact>();
    private final UsageContext runtimeUsage;
    private final UsageContext compileUsage;
    private final ConfigurationContainer configurations;

    public JavaLibrary(ObjectFactory objectFactory, ConfigurationContainer configurations, PublishArtifact... artifacts) {
        Collections.addAll(this.artifacts, artifacts);
        this.configurations = configurations;
        this.runtimeUsage = new RuntimeUsageContext(objectFactory.named(Usage.class, Usage.JAVA_RUNTIME));
        this.compileUsage = new CompileUsageContext(objectFactory.named(Usage.class, Usage.JAVA_API));
    }

    /**
     * This constructor should not be used, and is maintained only for backwards
     * compatibility with the widely used Shadow plugin.
     */
    @Deprecated
    public JavaLibrary(PublishArtifact jarArtifact, DependencySet runtimeDependencies) {
        this.artifacts.add(jarArtifact);
        this.runtimeUsage = new BackwardsCompatibilityUsageContext(DEPRECATED_OBJECT_FACTORY.named(Usage.class, Usage.JAVA_RUNTIME), runtimeDependencies);
        this.compileUsage = new BackwardsCompatibilityUsageContext(DEPRECATED_OBJECT_FACTORY.named(Usage.class, Usage.JAVA_API), runtimeDependencies);
        this.configurations = null;
    }

    public String getName() {
        return "java";
    }

    public Set<UsageContext> getUsages() {
        return ImmutableSet.of(runtimeUsage, compileUsage);
    }

    private class RuntimeUsageContext implements UsageContext {

        private final Usage usage;
        private DependencySet dependencies;

        public RuntimeUsageContext(Usage usage) {
            this.usage = usage;
        }

        @Override
        public Usage getUsage() {
            return usage;
        }

        public Set<PublishArtifact> getArtifacts() {
            return artifacts;
        }

        public Set<ModuleDependency> getDependencies() {
            if (dependencies == null) {
                dependencies = configurations.getByName(RUNTIME_ELEMENTS_CONFIGURATION_NAME).getAllDependencies();
            }
            return dependencies.withType(ModuleDependency.class);
        }
    }

    private class CompileUsageContext implements UsageContext {

        private final Usage usage;
        private DependencySet dependencies;

        public CompileUsageContext(Usage usage) {
            this.usage = usage;
        }

        @Override
        public Usage getUsage() {
            return usage;
        }

        public Set<PublishArtifact> getArtifacts() {
            return artifacts;
        }

        public Set<ModuleDependency> getDependencies() {
            if (dependencies == null) {
                dependencies = configurations.findByName(API_ELEMENTS_CONFIGURATION_NAME).getAllDependencies();
            }
            return dependencies.withType(ModuleDependency.class);
        }
    }

    private class BackwardsCompatibilityUsageContext implements UsageContext {

        private final Usage usage;
        private final DependencySet runtimeDependencies;

        private BackwardsCompatibilityUsageContext(Usage usage, DependencySet runtimeDependencies) {
            this.usage = usage;
            this.runtimeDependencies = runtimeDependencies;
        }

        @Override
        public Usage getUsage() {
            return usage;
        }

        @Override
        public Set<PublishArtifact> getArtifacts() {
            return artifacts;
        }

        @Override
        public Set<ModuleDependency> getDependencies() {
            return runtimeDependencies.withType(ModuleDependency.class);
        }
    }
}
