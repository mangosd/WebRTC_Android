// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file is autogenerated by
//     base/android/jni_generator/jni_generator.py
// For
//     org/webrtc/RtpSender

#ifndef org_webrtc_RtpSender_JNI
#define org_webrtc_RtpSender_JNI

#include <jni.h>

#include "../../../../../../../sdk/android/src/jni/jni_generator_helper.h"

// Step 1: forward declarations.
JNI_REGISTRATION_EXPORT extern const char kClassPath_org_webrtc_RtpSender[];
const char kClassPath_org_webrtc_RtpSender[] = "org/webrtc/RtpSender";

// Leaking this jclass as we cannot use LazyInstance from some threads.
JNI_REGISTRATION_EXPORT base::subtle::AtomicWord g_org_webrtc_RtpSender_clazz =
    0;
#ifndef org_webrtc_RtpSender_clazz_defined
#define org_webrtc_RtpSender_clazz_defined
inline jclass org_webrtc_RtpSender_clazz(JNIEnv* env) {
  return base::android::LazyGetClass(env, kClassPath_org_webrtc_RtpSender,
      &g_org_webrtc_RtpSender_clazz);
}
#endif

namespace webrtc {
namespace jni {

// Step 2: method stubs.

static jboolean JNI_RtpSender_SetTrack(JNIEnv* env, const
    base::android::JavaParamRef<jclass>& jcaller,
    jlong rtpSender,
    jlong nativeTrack);

JNI_GENERATOR_EXPORT jboolean Java_org_webrtc_RtpSender_nativeSetTrack(JNIEnv*
    env, jclass jcaller,
    jlong rtpSender,
    jlong nativeTrack) {
  return JNI_RtpSender_SetTrack(env, base::android::JavaParamRef<jclass>(env,
      jcaller), rtpSender, nativeTrack);
}

static jlong JNI_RtpSender_GetTrack(JNIEnv* env, const
    base::android::JavaParamRef<jclass>& jcaller,
    jlong rtpSender);

JNI_GENERATOR_EXPORT jlong Java_org_webrtc_RtpSender_nativeGetTrack(JNIEnv* env,
    jclass jcaller,
    jlong rtpSender) {
  return JNI_RtpSender_GetTrack(env, base::android::JavaParamRef<jclass>(env,
      jcaller), rtpSender);
}

static jlong JNI_RtpSender_GetDtmfSender(JNIEnv* env, const
    base::android::JavaParamRef<jclass>& jcaller,
    jlong rtpSender);

JNI_GENERATOR_EXPORT jlong Java_org_webrtc_RtpSender_nativeGetDtmfSender(JNIEnv*
    env, jclass jcaller,
    jlong rtpSender) {
  return JNI_RtpSender_GetDtmfSender(env,
      base::android::JavaParamRef<jclass>(env, jcaller), rtpSender);
}

static jboolean JNI_RtpSender_SetParameters(JNIEnv* env, const
    base::android::JavaParamRef<jclass>& jcaller,
    jlong rtpSender,
    const base::android::JavaParamRef<jobject>& parameters);

JNI_GENERATOR_EXPORT jboolean
    Java_org_webrtc_RtpSender_nativeSetParameters(JNIEnv* env, jclass jcaller,
    jlong rtpSender,
    jobject parameters) {
  return JNI_RtpSender_SetParameters(env,
      base::android::JavaParamRef<jclass>(env, jcaller), rtpSender,
      base::android::JavaParamRef<jobject>(env, parameters));
}

static base::android::ScopedJavaLocalRef<jobject>
    JNI_RtpSender_GetParameters(JNIEnv* env, const
    base::android::JavaParamRef<jclass>& jcaller,
    jlong rtpSender);

JNI_GENERATOR_EXPORT jobject
    Java_org_webrtc_RtpSender_nativeGetParameters(JNIEnv* env, jclass jcaller,
    jlong rtpSender) {
  return JNI_RtpSender_GetParameters(env,
      base::android::JavaParamRef<jclass>(env, jcaller), rtpSender).Release();
}

static base::android::ScopedJavaLocalRef<jstring> JNI_RtpSender_GetId(JNIEnv*
    env, const base::android::JavaParamRef<jclass>& jcaller,
    jlong rtpSender);

JNI_GENERATOR_EXPORT jstring Java_org_webrtc_RtpSender_nativeGetId(JNIEnv* env,
    jclass jcaller,
    jlong rtpSender) {
  return JNI_RtpSender_GetId(env, base::android::JavaParamRef<jclass>(env,
      jcaller), rtpSender).Release();
}

static base::subtle::AtomicWord g_org_webrtc_RtpSender_Constructor = 0;
static base::android::ScopedJavaLocalRef<jobject>
    Java_RtpSender_Constructor(JNIEnv* env, jlong nativeRtpSender) {
  CHECK_CLAZZ(env, org_webrtc_RtpSender_clazz(env),
      org_webrtc_RtpSender_clazz(env), NULL);
  jmethodID method_id =
      base::android::MethodID::LazyGet<
      base::android::MethodID::TYPE_INSTANCE>(
      env, org_webrtc_RtpSender_clazz(env),
      "<init>",
"("
"J"
")"
"V",
      &g_org_webrtc_RtpSender_Constructor);

  jobject ret =
      env->NewObject(org_webrtc_RtpSender_clazz(env),
          method_id, nativeRtpSender);
  jni_generator::CheckException(env);
  return base::android::ScopedJavaLocalRef<jobject>(env, ret);
}

}  // namespace jni
}  // namespace webrtc

#endif  // org_webrtc_RtpSender_JNI
