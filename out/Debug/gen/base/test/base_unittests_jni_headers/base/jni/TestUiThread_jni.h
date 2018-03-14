// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file is autogenerated by
//     base/android/jni_generator/jni_generator.py
// For
//     org/chromium/base/TestUiThread

#ifndef org_chromium_base_TestUiThread_JNI
#define org_chromium_base_TestUiThread_JNI

#include <jni.h>

#include "../../../../../../../../base/android/jni_generator/jni_generator_helper.h"

// Step 1: forward declarations.
JNI_REGISTRATION_EXPORT extern const char
    kClassPath_org_chromium_base_TestUiThread[];
const char kClassPath_org_chromium_base_TestUiThread[] =
    "org/chromium/base/TestUiThread";

// Leaking this jclass as we cannot use LazyInstance from some threads.
JNI_REGISTRATION_EXPORT base::subtle::AtomicWord
    g_org_chromium_base_TestUiThread_clazz = 0;
#ifndef org_chromium_base_TestUiThread_clazz_defined
#define org_chromium_base_TestUiThread_clazz_defined
inline jclass org_chromium_base_TestUiThread_clazz(JNIEnv* env) {
  return base::android::LazyGetClass(env,
      kClassPath_org_chromium_base_TestUiThread,
      &g_org_chromium_base_TestUiThread_clazz);
}
#endif

// Step 2: method stubs.

static base::subtle::AtomicWord g_org_chromium_base_TestUiThread_loop = 0;
static void Java_TestUiThread_loop(JNIEnv* env) {
  CHECK_CLAZZ(env, org_chromium_base_TestUiThread_clazz(env),
      org_chromium_base_TestUiThread_clazz(env));
  jmethodID method_id =
      base::android::MethodID::LazyGet<
      base::android::MethodID::TYPE_STATIC>(
      env, org_chromium_base_TestUiThread_clazz(env),
      "loop",
"("
")"
"V",
      &g_org_chromium_base_TestUiThread_loop);

     env->CallStaticVoidMethod(org_chromium_base_TestUiThread_clazz(env),
          method_id);
  jni_generator::CheckException(env);
}

#endif  // org_chromium_base_TestUiThread_JNI
