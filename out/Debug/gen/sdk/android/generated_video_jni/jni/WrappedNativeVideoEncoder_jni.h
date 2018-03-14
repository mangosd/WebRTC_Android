// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file is autogenerated by
//     base/android/jni_generator/jni_generator.py
// For
//     org/webrtc/WrappedNativeVideoEncoder

#ifndef org_webrtc_WrappedNativeVideoEncoder_JNI
#define org_webrtc_WrappedNativeVideoEncoder_JNI

#include <jni.h>

#include "../../../../../../../sdk/android/src/jni/jni_generator_helper.h"

// Step 1: forward declarations.
JNI_REGISTRATION_EXPORT extern const char
    kClassPath_org_webrtc_WrappedNativeVideoEncoder[];
const char kClassPath_org_webrtc_WrappedNativeVideoEncoder[] =
    "org/webrtc/WrappedNativeVideoEncoder";

// Leaking this jclass as we cannot use LazyInstance from some threads.
JNI_REGISTRATION_EXPORT base::subtle::AtomicWord
    g_org_webrtc_WrappedNativeVideoEncoder_clazz = 0;
#ifndef org_webrtc_WrappedNativeVideoEncoder_clazz_defined
#define org_webrtc_WrappedNativeVideoEncoder_clazz_defined
inline jclass org_webrtc_WrappedNativeVideoEncoder_clazz(JNIEnv* env) {
  return base::android::LazyGetClass(env,
      kClassPath_org_webrtc_WrappedNativeVideoEncoder,
      &g_org_webrtc_WrappedNativeVideoEncoder_clazz);
}
#endif

// Step 2: method stubs.

static base::subtle::AtomicWord
    g_org_webrtc_WrappedNativeVideoEncoder_createNativeEncoder = 0;
static jlong Java_WrappedNativeVideoEncoder_createNativeEncoder(JNIEnv* env,
    const base::android::JavaRef<jobject>& obj) {
  CHECK_CLAZZ(env, obj.obj(),
      org_webrtc_WrappedNativeVideoEncoder_clazz(env), 0);
  jmethodID method_id =
      base::android::MethodID::LazyGet<
      base::android::MethodID::TYPE_INSTANCE>(
      env, org_webrtc_WrappedNativeVideoEncoder_clazz(env),
      "createNativeEncoder",
"("
")"
"J",
      &g_org_webrtc_WrappedNativeVideoEncoder_createNativeEncoder);

  jlong ret =
      env->CallLongMethod(obj.obj(),
          method_id);
  jni_generator::CheckException(env);
  return ret;
}

static base::subtle::AtomicWord
    g_org_webrtc_WrappedNativeVideoEncoder_isWrappedSoftwareEncoder = 0;
static jboolean Java_WrappedNativeVideoEncoder_isWrappedSoftwareEncoder(JNIEnv*
    env, const base::android::JavaRef<jobject>& encoder) {
  CHECK_CLAZZ(env, org_webrtc_WrappedNativeVideoEncoder_clazz(env),
      org_webrtc_WrappedNativeVideoEncoder_clazz(env), false);
  jmethodID method_id =
      base::android::MethodID::LazyGet<
      base::android::MethodID::TYPE_STATIC>(
      env, org_webrtc_WrappedNativeVideoEncoder_clazz(env),
      "isWrappedSoftwareEncoder",
"("
"Lorg/webrtc/VideoEncoder;"
")"
"Z",
      &g_org_webrtc_WrappedNativeVideoEncoder_isWrappedSoftwareEncoder);

  jboolean ret =
env->CallStaticBooleanMethod(org_webrtc_WrappedNativeVideoEncoder_clazz(env),
          method_id, encoder.obj());
  jni_generator::CheckException(env);
  return ret;
}

static base::subtle::AtomicWord
    g_org_webrtc_WrappedNativeVideoEncoder_isInstanceOf = 0;
static jboolean Java_WrappedNativeVideoEncoder_isInstanceOf(JNIEnv* env, const
    base::android::JavaRef<jobject>& encoder) {
  CHECK_CLAZZ(env, org_webrtc_WrappedNativeVideoEncoder_clazz(env),
      org_webrtc_WrappedNativeVideoEncoder_clazz(env), false);
  jmethodID method_id =
      base::android::MethodID::LazyGet<
      base::android::MethodID::TYPE_STATIC>(
      env, org_webrtc_WrappedNativeVideoEncoder_clazz(env),
      "isInstanceOf",
"("
"Lorg/webrtc/VideoEncoder;"
")"
"Z",
      &g_org_webrtc_WrappedNativeVideoEncoder_isInstanceOf);

  jboolean ret =
env->CallStaticBooleanMethod(org_webrtc_WrappedNativeVideoEncoder_clazz(env),
          method_id, encoder.obj());
  jni_generator::CheckException(env);
  return ret;
}

#endif  // org_webrtc_WrappedNativeVideoEncoder_JNI
