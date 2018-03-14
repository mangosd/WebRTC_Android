// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file is autogenerated by
//     base/android/jni_generator/jni_generator.py
// For
//     org/webrtc/VideoDecoderFallback

#ifndef org_webrtc_VideoDecoderFallback_JNI
#define org_webrtc_VideoDecoderFallback_JNI

#include <jni.h>

#include "../../../../../../../sdk/android/src/jni/jni_generator_helper.h"

// Step 1: forward declarations.
JNI_REGISTRATION_EXPORT extern const char
    kClassPath_org_webrtc_VideoDecoderFallback[];
const char kClassPath_org_webrtc_VideoDecoderFallback[] =
    "org/webrtc/VideoDecoderFallback";

// Leaking this jclass as we cannot use LazyInstance from some threads.
JNI_REGISTRATION_EXPORT base::subtle::AtomicWord
    g_org_webrtc_VideoDecoderFallback_clazz = 0;
#ifndef org_webrtc_VideoDecoderFallback_clazz_defined
#define org_webrtc_VideoDecoderFallback_clazz_defined
inline jclass org_webrtc_VideoDecoderFallback_clazz(JNIEnv* env) {
  return base::android::LazyGetClass(env,
      kClassPath_org_webrtc_VideoDecoderFallback,
      &g_org_webrtc_VideoDecoderFallback_clazz);
}
#endif

namespace webrtc {
namespace jni {

// Step 2: method stubs.

static jlong JNI_VideoDecoderFallback_CreateDecoder(JNIEnv* env, const
    base::android::JavaParamRef<jclass>& jcaller,
    const base::android::JavaParamRef<jobject>& fallback,
    const base::android::JavaParamRef<jobject>& primary);

JNI_GENERATOR_EXPORT jlong
    Java_org_webrtc_VideoDecoderFallback_nativeCreateDecoder(JNIEnv* env, jclass
    jcaller,
    jobject fallback,
    jobject primary) {
  return JNI_VideoDecoderFallback_CreateDecoder(env,
      base::android::JavaParamRef<jclass>(env, jcaller),
      base::android::JavaParamRef<jobject>(env, fallback),
      base::android::JavaParamRef<jobject>(env, primary));
}

}  // namespace jni
}  // namespace webrtc

#endif  // org_webrtc_VideoDecoderFallback_JNI
