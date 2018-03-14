// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file is autogenerated by
//     base/android/jni_generator/jni_generator.py
// For
//     org/webrtc/AndroidVideoTrackSourceObserver

#ifndef org_webrtc_AndroidVideoTrackSourceObserver_JNI
#define org_webrtc_AndroidVideoTrackSourceObserver_JNI

#include <jni.h>

#include "../../../../../../../sdk/android/src/jni/jni_generator_helper.h"

// Step 1: forward declarations.
JNI_REGISTRATION_EXPORT extern const char
    kClassPath_org_webrtc_AndroidVideoTrackSourceObserver[];
const char kClassPath_org_webrtc_AndroidVideoTrackSourceObserver[] =
    "org/webrtc/AndroidVideoTrackSourceObserver";

// Leaking this jclass as we cannot use LazyInstance from some threads.
JNI_REGISTRATION_EXPORT base::subtle::AtomicWord
    g_org_webrtc_AndroidVideoTrackSourceObserver_clazz = 0;
#ifndef org_webrtc_AndroidVideoTrackSourceObserver_clazz_defined
#define org_webrtc_AndroidVideoTrackSourceObserver_clazz_defined
inline jclass org_webrtc_AndroidVideoTrackSourceObserver_clazz(JNIEnv* env) {
  return base::android::LazyGetClass(env,
      kClassPath_org_webrtc_AndroidVideoTrackSourceObserver,
      &g_org_webrtc_AndroidVideoTrackSourceObserver_clazz);
}
#endif

namespace webrtc {
namespace jni {

// Step 2: method stubs.

static void JNI_AndroidVideoTrackSourceObserver_CapturerStarted(JNIEnv* env,
    const base::android::JavaParamRef<jclass>& jcaller,
    jlong source,
    jboolean success);

JNI_GENERATOR_EXPORT void
    Java_org_webrtc_AndroidVideoTrackSourceObserver_nativeCapturerStarted(JNIEnv*
    env, jclass jcaller,
    jlong source,
    jboolean success) {
  return JNI_AndroidVideoTrackSourceObserver_CapturerStarted(env,
      base::android::JavaParamRef<jclass>(env, jcaller), source, success);
}

static void JNI_AndroidVideoTrackSourceObserver_CapturerStopped(JNIEnv* env,
    const base::android::JavaParamRef<jclass>& jcaller,
    jlong source);

JNI_GENERATOR_EXPORT void
    Java_org_webrtc_AndroidVideoTrackSourceObserver_nativeCapturerStopped(JNIEnv*
    env, jclass jcaller,
    jlong source) {
  return JNI_AndroidVideoTrackSourceObserver_CapturerStopped(env,
      base::android::JavaParamRef<jclass>(env, jcaller), source);
}

static void
    JNI_AndroidVideoTrackSourceObserver_OnByteBufferFrameCaptured(JNIEnv* env,
    const base::android::JavaParamRef<jclass>& jcaller,
    jlong source,
    const base::android::JavaParamRef<jbyteArray>& data,
    jint length,
    jint width,
    jint height,
    jint rotation,
    jlong timeStamp);

JNI_GENERATOR_EXPORT void
    Java_org_webrtc_AndroidVideoTrackSourceObserver_nativeOnByteBufferFrameCaptured(JNIEnv*
    env, jclass jcaller,
    jlong source,
    jbyteArray data,
    jint length,
    jint width,
    jint height,
    jint rotation,
    jlong timeStamp) {
  return JNI_AndroidVideoTrackSourceObserver_OnByteBufferFrameCaptured(env,
      base::android::JavaParamRef<jclass>(env, jcaller), source,
      base::android::JavaParamRef<jbyteArray>(env, data), length, width, height,
      rotation, timeStamp);
}

static void JNI_AndroidVideoTrackSourceObserver_OnTextureFrameCaptured(JNIEnv*
    env, const base::android::JavaParamRef<jclass>& jcaller,
    jlong source,
    jint width,
    jint height,
    jint oesTextureId,
    const base::android::JavaParamRef<jfloatArray>& transformMatrix,
    jint rotation,
    jlong timestamp);

JNI_GENERATOR_EXPORT void
    Java_org_webrtc_AndroidVideoTrackSourceObserver_nativeOnTextureFrameCaptured(JNIEnv*
    env, jclass jcaller,
    jlong source,
    jint width,
    jint height,
    jint oesTextureId,
    jfloatArray transformMatrix,
    jint rotation,
    jlong timestamp) {
  return JNI_AndroidVideoTrackSourceObserver_OnTextureFrameCaptured(env,
      base::android::JavaParamRef<jclass>(env, jcaller), source, width, height,
      oesTextureId, base::android::JavaParamRef<jfloatArray>(env,
      transformMatrix), rotation, timestamp);
}

static void JNI_AndroidVideoTrackSourceObserver_OnFrameCaptured(JNIEnv* env,
    const base::android::JavaParamRef<jclass>& jcaller,
    jlong source,
    jint width,
    jint height,
    jint rotation,
    jlong timestampNs,
    const base::android::JavaParamRef<jobject>& frame);

JNI_GENERATOR_EXPORT void
    Java_org_webrtc_AndroidVideoTrackSourceObserver_nativeOnFrameCaptured(JNIEnv*
    env, jclass jcaller,
    jlong source,
    jint width,
    jint height,
    jint rotation,
    jlong timestampNs,
    jobject frame) {
  return JNI_AndroidVideoTrackSourceObserver_OnFrameCaptured(env,
      base::android::JavaParamRef<jclass>(env, jcaller), source, width, height,
      rotation, timestampNs, base::android::JavaParamRef<jobject>(env, frame));
}

}  // namespace jni
}  // namespace webrtc

#endif  // org_webrtc_AndroidVideoTrackSourceObserver_JNI
