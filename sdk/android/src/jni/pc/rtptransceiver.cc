/*
 *  Copyright 2018 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#include "sdk/android/src/jni/pc/rtptransceiver.h"

#include <string>

#include "sdk/android/generated_peerconnection_jni/jni/RtpTransceiver_jni.h"
#include "sdk/android/native_api/jni/java_types.h"
#include "sdk/android/src/jni/jni_helpers.h"
#include "sdk/android/src/jni/pc/mediastreamtrack.h"
#include "sdk/android/src/jni/pc/rtpparameters.h"
#include "sdk/android/src/jni/pc/rtpreceiver.h"
#include "sdk/android/src/jni/pc/rtpsender.h"

namespace webrtc {
namespace jni {

namespace {

ScopedJavaLocalRef<jobject> NativeToJavaRtpTransceiverDirection(
    JNIEnv* jni,
    RtpTransceiverDirection rtp_transceiver_direction) {
  return Java_RtpTransceiverDirection_fromNativeIndex(
      jni, static_cast<int>(rtp_transceiver_direction));
}

}  // namespace

RtpTransceiverInit JavaToNativeRtpTransceiverInit(
    JNIEnv* jni,
    const JavaRef<jobject>& j_init) {
  RtpTransceiverInit init;

  // Convert the direction.
  init.direction = static_cast<RtpTransceiverDirection>(
      Java_RtpTransceiverInit_getDirectionNativeIndex(jni, j_init));

  // Convert the stream ids.
  ScopedJavaLocalRef<jobject> j_stream_ids =
      Java_RtpTransceiverInit_getStreamIds(jni, j_init);
  init.stream_ids = JavaListToNativeVector<std::string, jstring>(
      jni, j_stream_ids, &JavaToNativeString);
  return init;
}

ScopedJavaLocalRef<jobject> NativeToJavaRtpTransceiver(
    JNIEnv* env,
    rtc::scoped_refptr<RtpTransceiverInterface> transceiver) {
  if (!transceiver) {
    return nullptr;
  }
  // Transceiver will now have shared ownership by the Java object.
  return Java_RtpTransceiver_Constructor(
      env, jlongFromPointer(transceiver.release()));
}

ScopedJavaLocalRef<jobject> JNI_RtpTransceiver_GetMediaType(
    JNIEnv* jni,
    const base::android::JavaParamRef<jclass>&,
    jlong j_rtp_transceiver_pointer) {
  return NativeToJavaMediaType(
      jni, reinterpret_cast<RtpTransceiverInterface*>(j_rtp_transceiver_pointer)
               ->media_type());
}

ScopedJavaLocalRef<jstring> JNI_RtpTransceiver_GetMid(
    JNIEnv* jni,
    const base::android::JavaParamRef<jclass>&,
    jlong j_rtp_transceiver_pointer) {
  rtc::Optional<std::string> mid =
      reinterpret_cast<RtpTransceiverInterface*>(j_rtp_transceiver_pointer)
          ->mid();
  return NativeToJavaString(jni, mid);
}

ScopedJavaLocalRef<jobject> JNI_RtpTransceiver_GetSender(
    JNIEnv* jni,
    const base::android::JavaParamRef<jclass>&,
    jlong j_rtp_transceiver_pointer) {
  return NativeToJavaRtpSender(
      jni, reinterpret_cast<RtpTransceiverInterface*>(j_rtp_transceiver_pointer)
               ->sender());
}

ScopedJavaLocalRef<jobject> JNI_RtpTransceiver_GetReceiver(
    JNIEnv* jni,
    const base::android::JavaParamRef<jclass>&,
    jlong j_rtp_transceiver_pointer) {
  return NativeToJavaRtpReceiver(
      jni, reinterpret_cast<RtpTransceiverInterface*>(j_rtp_transceiver_pointer)
               ->receiver());
}

jboolean JNI_RtpTransceiver_Stopped(JNIEnv* jni,
                                    const base::android::JavaParamRef<jclass>&,
                                    jlong j_rtp_transceiver_pointer) {
  return reinterpret_cast<RtpTransceiverInterface*>(j_rtp_transceiver_pointer)
      ->stopped();
}

ScopedJavaLocalRef<jobject> JNI_RtpTransceiver_Direction(
    JNIEnv* jni,
    const base::android::JavaParamRef<jclass>&,
    jlong j_rtp_transceiver_pointer) {
  return NativeToJavaRtpTransceiverDirection(
      jni, reinterpret_cast<RtpTransceiverInterface*>(j_rtp_transceiver_pointer)
               ->direction());
}

ScopedJavaLocalRef<jobject> JNI_RtpTransceiver_CurrentDirection(
    JNIEnv* jni,
    const base::android::JavaParamRef<jclass>&,
    jlong j_rtp_transceiver_pointer) {
  rtc::Optional<RtpTransceiverDirection> direction =
      reinterpret_cast<RtpTransceiverInterface*>(j_rtp_transceiver_pointer)
          ->current_direction();
  return direction ? NativeToJavaRtpTransceiverDirection(jni, *direction)
                   : nullptr;
}

void JNI_RtpTransceiver_Stop(JNIEnv* jni,
                             const base::android::JavaParamRef<jclass>&,
                             jlong j_rtp_transceiver_pointer) {
  reinterpret_cast<RtpTransceiverInterface*>(j_rtp_transceiver_pointer)->Stop();
}

void JNI_RtpTransceiver_SetDirection(
    JNIEnv* jni,
    const base::android::JavaParamRef<jclass>&,
    jlong j_rtp_transceiver_pointer,
    const base::android::JavaParamRef<jobject>& j_rtp_transceiver_direction) {
  if (IsNull(jni, j_rtp_transceiver_direction)) {
    return;
  }
  RtpTransceiverDirection direction = static_cast<RtpTransceiverDirection>(
      Java_RtpTransceiverDirection_getNativeIndex(jni,
                                                  j_rtp_transceiver_direction));
  reinterpret_cast<RtpTransceiverInterface*>(j_rtp_transceiver_pointer)
      ->SetDirection(direction);
}

}  // namespace jni
}  // namespace webrtc
