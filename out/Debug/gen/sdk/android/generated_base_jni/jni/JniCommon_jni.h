// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file is autogenerated by
//     base/android/jni_generator/jni_generator.py
// For
//     org/webrtc/JniCommon

#ifndef org_webrtc_JniCommon_JNI
#define org_webrtc_JniCommon_JNI

#include <jni.h>

#include "../../../../../../../sdk/android/src/jni/jni_generator_helper.h"

// Step 1: forward declarations.
JNI_REGISTRATION_EXPORT extern const char kClassPath_org_webrtc_JniCommon[];
const char kClassPath_org_webrtc_JniCommon[] = "org/webrtc/JniCommon";

// Leaking this jclass as we cannot use LazyInstance from some threads.
JNI_REGISTRATION_EXPORT base::subtle::AtomicWord g_org_webrtc_JniCommon_clazz =
    0;
#ifndef org_webrtc_JniCommon_clazz_defined
#define org_webrtc_JniCommon_clazz_defined
inline jclass org_webrtc_JniCommon_clazz(JNIEnv* env) {
  return base::android::LazyGetClass(env, kClassPath_org_webrtc_JniCommon,
      &g_org_webrtc_JniCommon_clazz);
}
#endif

namespace webrtc {
namespace jni {

// Step 2: method stubs.

static void JNI_JniCommon_AddRef(JNIEnv* env, const
    base::android::JavaParamRef<jclass>& jcaller,
    jlong refCountedPointer);

JNI_GENERATOR_EXPORT void Java_org_webrtc_JniCommon_nativeAddRef(JNIEnv* env,
    jclass jcaller,
    jlong refCountedPointer) {
  return JNI_JniCommon_AddRef(env, base::android::JavaParamRef<jclass>(env,
      jcaller), refCountedPointer);
}

static void JNI_JniCommon_ReleaseRef(JNIEnv* env, const
    base::android::JavaParamRef<jclass>& jcaller,
    jlong refCountedPointer);

JNI_GENERATOR_EXPORT void Java_org_webrtc_JniCommon_nativeReleaseRef(JNIEnv*
    env, jclass jcaller,
    jlong refCountedPointer) {
  return JNI_JniCommon_ReleaseRef(env, base::android::JavaParamRef<jclass>(env,
      jcaller), refCountedPointer);
}

static base::android::ScopedJavaLocalRef<jobject>
    JNI_JniCommon_AllocateByteBuffer(JNIEnv* env, const
    base::android::JavaParamRef<jclass>& jcaller,
    jint size);

JNI_GENERATOR_EXPORT jobject
    Java_org_webrtc_JniCommon_nativeAllocateByteBuffer(JNIEnv* env, jclass
    jcaller,
    jint size) {
  return JNI_JniCommon_AllocateByteBuffer(env,
      base::android::JavaParamRef<jclass>(env, jcaller), size).Release();
}

static void JNI_JniCommon_FreeByteBuffer(JNIEnv* env, const
    base::android::JavaParamRef<jclass>& jcaller,
    const base::android::JavaParamRef<jobject>& buffer);

JNI_GENERATOR_EXPORT void Java_org_webrtc_JniCommon_nativeFreeByteBuffer(JNIEnv*
    env, jclass jcaller,
    jobject buffer) {
  return JNI_JniCommon_FreeByteBuffer(env,
      base::android::JavaParamRef<jclass>(env, jcaller),
      base::android::JavaParamRef<jobject>(env, buffer));
}

}  // namespace jni
}  // namespace webrtc

#endif  // org_webrtc_JniCommon_JNI
