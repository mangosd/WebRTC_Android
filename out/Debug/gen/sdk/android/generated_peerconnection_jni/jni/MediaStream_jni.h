// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file is autogenerated by
//     base/android/jni_generator/jni_generator.py
// For
//     org/webrtc/MediaStream

#ifndef org_webrtc_MediaStream_JNI
#define org_webrtc_MediaStream_JNI

#include <jni.h>

#include "../../../../../../../sdk/android/src/jni/jni_generator_helper.h"

// Step 1: forward declarations.
JNI_REGISTRATION_EXPORT extern const char kClassPath_org_webrtc_MediaStream[];
const char kClassPath_org_webrtc_MediaStream[] = "org/webrtc/MediaStream";

// Leaking this jclass as we cannot use LazyInstance from some threads.
JNI_REGISTRATION_EXPORT base::subtle::AtomicWord g_org_webrtc_MediaStream_clazz
    = 0;
#ifndef org_webrtc_MediaStream_clazz_defined
#define org_webrtc_MediaStream_clazz_defined
inline jclass org_webrtc_MediaStream_clazz(JNIEnv* env) {
  return base::android::LazyGetClass(env, kClassPath_org_webrtc_MediaStream,
      &g_org_webrtc_MediaStream_clazz);
}
#endif

namespace webrtc {
namespace jni {

// Step 2: method stubs.

static jboolean JNI_MediaStream_AddAudioTrackToNativeStream(JNIEnv* env, const
    base::android::JavaParamRef<jclass>& jcaller,
    jlong stream,
    jlong nativeAudioTrack);

JNI_GENERATOR_EXPORT jboolean
    Java_org_webrtc_MediaStream_nativeAddAudioTrackToNativeStream(JNIEnv* env,
    jclass jcaller,
    jlong stream,
    jlong nativeAudioTrack) {
  return JNI_MediaStream_AddAudioTrackToNativeStream(env,
      base::android::JavaParamRef<jclass>(env, jcaller), stream,
      nativeAudioTrack);
}

static jboolean JNI_MediaStream_AddVideoTrackToNativeStream(JNIEnv* env, const
    base::android::JavaParamRef<jclass>& jcaller,
    jlong stream,
    jlong nativeVideoTrack);

JNI_GENERATOR_EXPORT jboolean
    Java_org_webrtc_MediaStream_nativeAddVideoTrackToNativeStream(JNIEnv* env,
    jclass jcaller,
    jlong stream,
    jlong nativeVideoTrack) {
  return JNI_MediaStream_AddVideoTrackToNativeStream(env,
      base::android::JavaParamRef<jclass>(env, jcaller), stream,
      nativeVideoTrack);
}

static jboolean JNI_MediaStream_RemoveAudioTrack(JNIEnv* env, const
    base::android::JavaParamRef<jclass>& jcaller,
    jlong stream,
    jlong nativeAudioTrack);

JNI_GENERATOR_EXPORT jboolean
    Java_org_webrtc_MediaStream_nativeRemoveAudioTrack(JNIEnv* env, jclass
    jcaller,
    jlong stream,
    jlong nativeAudioTrack) {
  return JNI_MediaStream_RemoveAudioTrack(env,
      base::android::JavaParamRef<jclass>(env, jcaller), stream,
      nativeAudioTrack);
}

static jboolean JNI_MediaStream_RemoveVideoTrack(JNIEnv* env, const
    base::android::JavaParamRef<jclass>& jcaller,
    jlong stream,
    jlong nativeVideoTrack);

JNI_GENERATOR_EXPORT jboolean
    Java_org_webrtc_MediaStream_nativeRemoveVideoTrack(JNIEnv* env, jclass
    jcaller,
    jlong stream,
    jlong nativeVideoTrack) {
  return JNI_MediaStream_RemoveVideoTrack(env,
      base::android::JavaParamRef<jclass>(env, jcaller), stream,
      nativeVideoTrack);
}

static base::android::ScopedJavaLocalRef<jstring> JNI_MediaStream_GetId(JNIEnv*
    env, const base::android::JavaParamRef<jclass>& jcaller,
    jlong stream);

JNI_GENERATOR_EXPORT jstring Java_org_webrtc_MediaStream_nativeGetId(JNIEnv*
    env, jclass jcaller,
    jlong stream) {
  return JNI_MediaStream_GetId(env, base::android::JavaParamRef<jclass>(env,
      jcaller), stream).Release();
}

static base::subtle::AtomicWord g_org_webrtc_MediaStream_Constructor = 0;
static base::android::ScopedJavaLocalRef<jobject>
    Java_MediaStream_Constructor(JNIEnv* env, jlong nativeStream) {
  CHECK_CLAZZ(env, org_webrtc_MediaStream_clazz(env),
      org_webrtc_MediaStream_clazz(env), NULL);
  jmethodID method_id =
      base::android::MethodID::LazyGet<
      base::android::MethodID::TYPE_INSTANCE>(
      env, org_webrtc_MediaStream_clazz(env),
      "<init>",
"("
"J"
")"
"V",
      &g_org_webrtc_MediaStream_Constructor);

  jobject ret =
      env->NewObject(org_webrtc_MediaStream_clazz(env),
          method_id, nativeStream);
  jni_generator::CheckException(env);
  return base::android::ScopedJavaLocalRef<jobject>(env, ret);
}

static base::subtle::AtomicWord g_org_webrtc_MediaStream_dispose = 0;
static void Java_MediaStream_dispose(JNIEnv* env, const
    base::android::JavaRef<jobject>& obj) {
  CHECK_CLAZZ(env, obj.obj(),
      org_webrtc_MediaStream_clazz(env));
  jmethodID method_id =
      base::android::MethodID::LazyGet<
      base::android::MethodID::TYPE_INSTANCE>(
      env, org_webrtc_MediaStream_clazz(env),
      "dispose",
"("
")"
"V",
      &g_org_webrtc_MediaStream_dispose);

     env->CallVoidMethod(obj.obj(),
          method_id);
  jni_generator::CheckException(env);
}

static base::subtle::AtomicWord g_org_webrtc_MediaStream_addNativeAudioTrack =
    0;
static void Java_MediaStream_addNativeAudioTrack(JNIEnv* env, const
    base::android::JavaRef<jobject>& obj, jlong nativeTrack) {
  CHECK_CLAZZ(env, obj.obj(),
      org_webrtc_MediaStream_clazz(env));
  jmethodID method_id =
      base::android::MethodID::LazyGet<
      base::android::MethodID::TYPE_INSTANCE>(
      env, org_webrtc_MediaStream_clazz(env),
      "addNativeAudioTrack",
"("
"J"
")"
"V",
      &g_org_webrtc_MediaStream_addNativeAudioTrack);

     env->CallVoidMethod(obj.obj(),
          method_id, nativeTrack);
  jni_generator::CheckException(env);
}

static base::subtle::AtomicWord g_org_webrtc_MediaStream_addNativeVideoTrack =
    0;
static void Java_MediaStream_addNativeVideoTrack(JNIEnv* env, const
    base::android::JavaRef<jobject>& obj, jlong nativeTrack) {
  CHECK_CLAZZ(env, obj.obj(),
      org_webrtc_MediaStream_clazz(env));
  jmethodID method_id =
      base::android::MethodID::LazyGet<
      base::android::MethodID::TYPE_INSTANCE>(
      env, org_webrtc_MediaStream_clazz(env),
      "addNativeVideoTrack",
"("
"J"
")"
"V",
      &g_org_webrtc_MediaStream_addNativeVideoTrack);

     env->CallVoidMethod(obj.obj(),
          method_id, nativeTrack);
  jni_generator::CheckException(env);
}

static base::subtle::AtomicWord g_org_webrtc_MediaStream_removeAudioTrack = 0;
static void Java_MediaStream_removeAudioTrack(JNIEnv* env, const
    base::android::JavaRef<jobject>& obj, jlong nativeTrack) {
  CHECK_CLAZZ(env, obj.obj(),
      org_webrtc_MediaStream_clazz(env));
  jmethodID method_id =
      base::android::MethodID::LazyGet<
      base::android::MethodID::TYPE_INSTANCE>(
      env, org_webrtc_MediaStream_clazz(env),
      "removeAudioTrack",
"("
"J"
")"
"V",
      &g_org_webrtc_MediaStream_removeAudioTrack);

     env->CallVoidMethod(obj.obj(),
          method_id, nativeTrack);
  jni_generator::CheckException(env);
}

static base::subtle::AtomicWord g_org_webrtc_MediaStream_removeVideoTrack = 0;
static void Java_MediaStream_removeVideoTrack(JNIEnv* env, const
    base::android::JavaRef<jobject>& obj, jlong nativeTrack) {
  CHECK_CLAZZ(env, obj.obj(),
      org_webrtc_MediaStream_clazz(env));
  jmethodID method_id =
      base::android::MethodID::LazyGet<
      base::android::MethodID::TYPE_INSTANCE>(
      env, org_webrtc_MediaStream_clazz(env),
      "removeVideoTrack",
"("
"J"
")"
"V",
      &g_org_webrtc_MediaStream_removeVideoTrack);

     env->CallVoidMethod(obj.obj(),
          method_id, nativeTrack);
  jni_generator::CheckException(env);
}

}  // namespace jni
}  // namespace webrtc

#endif  // org_webrtc_MediaStream_JNI
