// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file is autogenerated by
//     base/android/jni_generator/jni_generator.py
// For
//     org/chromium/base/process_launcher/ChildProcessService

#ifndef org_chromium_base_process_launcher_ChildProcessService_JNI
#define org_chromium_base_process_launcher_ChildProcessService_JNI

#include <jni.h>

#include "../../../../../../../base/android/jni_generator/jni_generator_helper.h"

// Step 1: forward declarations.
JNI_REGISTRATION_EXPORT extern const char
    kClassPath_org_chromium_base_process_1launcher_ChildProcessService[];
const char kClassPath_org_chromium_base_process_1launcher_ChildProcessService[]
    = "org/chromium/base/process_launcher/ChildProcessService";

// Leaking this jclass as we cannot use LazyInstance from some threads.
JNI_REGISTRATION_EXPORT base::subtle::AtomicWord
    g_org_chromium_base_process_1launcher_ChildProcessService_clazz = 0;
#ifndef org_chromium_base_process_1launcher_ChildProcessService_clazz_defined
#define org_chromium_base_process_1launcher_ChildProcessService_clazz_defined
inline jclass
    org_chromium_base_process_1launcher_ChildProcessService_clazz(JNIEnv* env) {
  return base::android::LazyGetClass(env,
      kClassPath_org_chromium_base_process_1launcher_ChildProcessService,
      &g_org_chromium_base_process_1launcher_ChildProcessService_clazz);
}
#endif

namespace base {
namespace android {

// Step 2: method stubs.

static void JNI_ChildProcessService_RegisterFileDescriptors(JNIEnv* env, const
    base::android::JavaParamRef<jclass>& jcaller,
    const base::android::JavaParamRef<jobjectArray>& keys,
    const base::android::JavaParamRef<jintArray>& id,
    const base::android::JavaParamRef<jintArray>& fd,
    const base::android::JavaParamRef<jlongArray>& offset,
    const base::android::JavaParamRef<jlongArray>& size);

JNI_GENERATOR_EXPORT void
    Java_org_chromium_base_process_1launcher_ChildProcessService_nativeRegisterFileDescriptors(JNIEnv*
    env, jclass jcaller,
    jobjectArray keys,
    jintArray id,
    jintArray fd,
    jlongArray offset,
    jlongArray size) {
  return JNI_ChildProcessService_RegisterFileDescriptors(env,
      base::android::JavaParamRef<jclass>(env, jcaller),
      base::android::JavaParamRef<jobjectArray>(env, keys),
      base::android::JavaParamRef<jintArray>(env, id),
      base::android::JavaParamRef<jintArray>(env, fd),
      base::android::JavaParamRef<jlongArray>(env, offset),
      base::android::JavaParamRef<jlongArray>(env, size));
}

static void JNI_ChildProcessService_ExitChildProcess(JNIEnv* env, const
    base::android::JavaParamRef<jclass>& jcaller);

JNI_GENERATOR_EXPORT void
    Java_org_chromium_base_process_1launcher_ChildProcessService_nativeExitChildProcess(JNIEnv*
    env, jclass jcaller) {
  return JNI_ChildProcessService_ExitChildProcess(env,
      base::android::JavaParamRef<jclass>(env, jcaller));
}

}  // namespace android
}  // namespace base

#endif  // org_chromium_base_process_launcher_ChildProcessService_JNI
