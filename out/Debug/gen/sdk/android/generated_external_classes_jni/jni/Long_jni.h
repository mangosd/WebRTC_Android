// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file is autogenerated by
//     base/android/jni_generator/jni_generator.py
// For
//     java/lang/Long

#ifndef java_lang_Long_JNI
#define java_lang_Long_JNI

#include <jni.h>

#include "../../../../../../../sdk/android/src/jni/jni_generator_helper.h"

// Step 1: forward declarations.
JNI_REGISTRATION_EXPORT extern const char kClassPath_java_lang_Long[];
const char kClassPath_java_lang_Long[] = "java/lang/Long";

// Leaking this jclass as we cannot use LazyInstance from some threads.
JNI_REGISTRATION_EXPORT base::subtle::AtomicWord g_java_lang_Long_clazz = 0;
#ifndef java_lang_Long_clazz_defined
#define java_lang_Long_clazz_defined
inline jclass java_lang_Long_clazz(JNIEnv* env) {
  return base::android::LazyGetClass(env, kClassPath_java_lang_Long,
      &g_java_lang_Long_clazz);
}
#endif

namespace JNI_Long {

enum Java_Long_constant_fields {
  BYTES = 8,
  SIZE = 64,
};

// Step 2: method stubs.

static base::subtle::AtomicWord g_java_lang_Long_toStringJLS_J_I = 0;
static base::android::ScopedJavaLocalRef<jstring>
    Java_Long_toStringJLS_J_I(JNIEnv* env, jlong p0,
    JniIntWrapper p1) __attribute__ ((unused));
static base::android::ScopedJavaLocalRef<jstring>
    Java_Long_toStringJLS_J_I(JNIEnv* env, jlong p0,
    JniIntWrapper p1) {
  CHECK_CLAZZ(env, java_lang_Long_clazz(env),
      java_lang_Long_clazz(env), NULL);
  jmethodID method_id =
      base::android::MethodID::LazyGet<
      base::android::MethodID::TYPE_STATIC>(
      env, java_lang_Long_clazz(env),
      "toString",
      "(JI)Ljava/lang/String;",
      &g_java_lang_Long_toStringJLS_J_I);

  jstring ret =
static_cast<jstring>(env->CallStaticObjectMethod(java_lang_Long_clazz(env),
          method_id, p0, as_jint(p1)));
  jni_generator::CheckException(env);
  return base::android::ScopedJavaLocalRef<jstring>(env, ret);
}

static base::subtle::AtomicWord g_java_lang_Long_toUnsignedStringJLS_J_I = 0;
static base::android::ScopedJavaLocalRef<jstring>
    Java_Long_toUnsignedStringJLS_J_I(JNIEnv* env, jlong p0,
    JniIntWrapper p1) __attribute__ ((unused));
static base::android::ScopedJavaLocalRef<jstring>
    Java_Long_toUnsignedStringJLS_J_I(JNIEnv* env, jlong p0,
    JniIntWrapper p1) {
  CHECK_CLAZZ(env, java_lang_Long_clazz(env),
      java_lang_Long_clazz(env), NULL);
  jmethodID method_id =
      base::android::MethodID::LazyGet<
      base::android::MethodID::TYPE_STATIC>(
      env, java_lang_Long_clazz(env),
      "toUnsignedString",
      "(JI)Ljava/lang/String;",
      &g_java_lang_Long_toUnsignedStringJLS_J_I);

  jstring ret =
static_cast<jstring>(env->CallStaticObjectMethod(java_lang_Long_clazz(env),
          method_id, p0, as_jint(p1)));
  jni_generator::CheckException(env);
  return base::android::ScopedJavaLocalRef<jstring>(env, ret);
}

static base::subtle::AtomicWord g_java_lang_Long_toHexString = 0;
static base::android::ScopedJavaLocalRef<jstring> Java_Long_toHexString(JNIEnv*
    env, jlong p0) __attribute__ ((unused));
static base::android::ScopedJavaLocalRef<jstring> Java_Long_toHexString(JNIEnv*
    env, jlong p0) {
  CHECK_CLAZZ(env, java_lang_Long_clazz(env),
      java_lang_Long_clazz(env), NULL);
  jmethodID method_id =
      base::android::MethodID::LazyGet<
      base::android::MethodID::TYPE_STATIC>(
      env, java_lang_Long_clazz(env),
      "toHexString",
      "(J)Ljava/lang/String;",
      &g_java_lang_Long_toHexString);

  jstring ret =
static_cast<jstring>(env->CallStaticObjectMethod(java_lang_Long_clazz(env),
          method_id, p0));
  jni_generator::CheckException(env);
  return base::android::ScopedJavaLocalRef<jstring>(env, ret);
}

static base::subtle::AtomicWord g_java_lang_Long_toOctalString = 0;
static base::android::ScopedJavaLocalRef<jstring>
    Java_Long_toOctalString(JNIEnv* env, jlong p0) __attribute__ ((unused));
static base::android::ScopedJavaLocalRef<jstring>
    Java_Long_toOctalString(JNIEnv* env, jlong p0) {
  CHECK_CLAZZ(env, java_lang_Long_clazz(env),
      java_lang_Long_clazz(env), NULL);
  jmethodID method_id =
      base::android::MethodID::LazyGet<
      base::android::MethodID::TYPE_STATIC>(
      env, java_lang_Long_clazz(env),
      "toOctalString",
      "(J)Ljava/lang/String;",
      &g_java_lang_Long_toOctalString);

  jstring ret =
static_cast<jstring>(env->CallStaticObjectMethod(java_lang_Long_clazz(env),
          method_id, p0));
  jni_generator::CheckException(env);
  return base::android::ScopedJavaLocalRef<jstring>(env, ret);
}

static base::subtle::AtomicWord g_java_lang_Long_toBinaryString = 0;
static base::android::ScopedJavaLocalRef<jstring>
    Java_Long_toBinaryString(JNIEnv* env, jlong p0) __attribute__ ((unused));
static base::android::ScopedJavaLocalRef<jstring>
    Java_Long_toBinaryString(JNIEnv* env, jlong p0) {
  CHECK_CLAZZ(env, java_lang_Long_clazz(env),
      java_lang_Long_clazz(env), NULL);
  jmethodID method_id =
      base::android::MethodID::LazyGet<
      base::android::MethodID::TYPE_STATIC>(
      env, java_lang_Long_clazz(env),
      "toBinaryString",
      "(J)Ljava/lang/String;",
      &g_java_lang_Long_toBinaryString);

  jstring ret =
static_cast<jstring>(env->CallStaticObjectMethod(java_lang_Long_clazz(env),
          method_id, p0));
  jni_generator::CheckException(env);
  return base::android::ScopedJavaLocalRef<jstring>(env, ret);
}

static base::subtle::AtomicWord g_java_lang_Long_toStringJLS_J = 0;
static base::android::ScopedJavaLocalRef<jstring>
    Java_Long_toStringJLS_J(JNIEnv* env, jlong p0) __attribute__ ((unused));
static base::android::ScopedJavaLocalRef<jstring>
    Java_Long_toStringJLS_J(JNIEnv* env, jlong p0) {
  CHECK_CLAZZ(env, java_lang_Long_clazz(env),
      java_lang_Long_clazz(env), NULL);
  jmethodID method_id =
      base::android::MethodID::LazyGet<
      base::android::MethodID::TYPE_STATIC>(
      env, java_lang_Long_clazz(env),
      "toString",
      "(J)Ljava/lang/String;",
      &g_java_lang_Long_toStringJLS_J);

  jstring ret =
static_cast<jstring>(env->CallStaticObjectMethod(java_lang_Long_clazz(env),
          method_id, p0));
  jni_generator::CheckException(env);
  return base::android::ScopedJavaLocalRef<jstring>(env, ret);
}

static base::subtle::AtomicWord g_java_lang_Long_toUnsignedStringJLS_J = 0;
static base::android::ScopedJavaLocalRef<jstring>
    Java_Long_toUnsignedStringJLS_J(JNIEnv* env, jlong p0) __attribute__
    ((unused));
static base::android::ScopedJavaLocalRef<jstring>
    Java_Long_toUnsignedStringJLS_J(JNIEnv* env, jlong p0) {
  CHECK_CLAZZ(env, java_lang_Long_clazz(env),
      java_lang_Long_clazz(env), NULL);
  jmethodID method_id =
      base::android::MethodID::LazyGet<
      base::android::MethodID::TYPE_STATIC>(
      env, java_lang_Long_clazz(env),
      "toUnsignedString",
      "(J)Ljava/lang/String;",
      &g_java_lang_Long_toUnsignedStringJLS_J);

  jstring ret =
static_cast<jstring>(env->CallStaticObjectMethod(java_lang_Long_clazz(env),
          method_id, p0));
  jni_generator::CheckException(env);
  return base::android::ScopedJavaLocalRef<jstring>(env, ret);
}

static base::subtle::AtomicWord g_java_lang_Long_parseLongJ_JLS_I = 0;
static jlong Java_Long_parseLongJ_JLS_I(JNIEnv* env, const
    base::android::JavaRef<jstring>& p0,
    JniIntWrapper p1) __attribute__ ((unused));
static jlong Java_Long_parseLongJ_JLS_I(JNIEnv* env, const
    base::android::JavaRef<jstring>& p0,
    JniIntWrapper p1) {
  CHECK_CLAZZ(env, java_lang_Long_clazz(env),
      java_lang_Long_clazz(env), 0);
  jmethodID method_id =
      base::android::MethodID::LazyGet<
      base::android::MethodID::TYPE_STATIC>(
      env, java_lang_Long_clazz(env),
      "parseLong",
      "(Ljava/lang/String;I)J",
      &g_java_lang_Long_parseLongJ_JLS_I);

  jlong ret =
      env->CallStaticLongMethod(java_lang_Long_clazz(env),
          method_id, p0.obj(), as_jint(p1));
  jni_generator::CheckException(env);
  return ret;
}

static base::subtle::AtomicWord g_java_lang_Long_parseLongJ_JLS = 0;
static jlong Java_Long_parseLongJ_JLS(JNIEnv* env, const
    base::android::JavaRef<jstring>& p0) __attribute__ ((unused));
static jlong Java_Long_parseLongJ_JLS(JNIEnv* env, const
    base::android::JavaRef<jstring>& p0) {
  CHECK_CLAZZ(env, java_lang_Long_clazz(env),
      java_lang_Long_clazz(env), 0);
  jmethodID method_id =
      base::android::MethodID::LazyGet<
      base::android::MethodID::TYPE_STATIC>(
      env, java_lang_Long_clazz(env),
      "parseLong",
      "(Ljava/lang/String;)J",
      &g_java_lang_Long_parseLongJ_JLS);

  jlong ret =
      env->CallStaticLongMethod(java_lang_Long_clazz(env),
          method_id, p0.obj());
  jni_generator::CheckException(env);
  return ret;
}

static base::subtle::AtomicWord g_java_lang_Long_parseUnsignedLongJ_JLS_I = 0;
static jlong Java_Long_parseUnsignedLongJ_JLS_I(JNIEnv* env, const
    base::android::JavaRef<jstring>& p0,
    JniIntWrapper p1) __attribute__ ((unused));
static jlong Java_Long_parseUnsignedLongJ_JLS_I(JNIEnv* env, const
    base::android::JavaRef<jstring>& p0,
    JniIntWrapper p1) {
  CHECK_CLAZZ(env, java_lang_Long_clazz(env),
      java_lang_Long_clazz(env), 0);
  jmethodID method_id =
      base::android::MethodID::LazyGet<
      base::android::MethodID::TYPE_STATIC>(
      env, java_lang_Long_clazz(env),
      "parseUnsignedLong",
      "(Ljava/lang/String;I)J",
      &g_java_lang_Long_parseUnsignedLongJ_JLS_I);

  jlong ret =
      env->CallStaticLongMethod(java_lang_Long_clazz(env),
          method_id, p0.obj(), as_jint(p1));
  jni_generator::CheckException(env);
  return ret;
}

static base::subtle::AtomicWord g_java_lang_Long_parseUnsignedLongJ_JLS = 0;
static jlong Java_Long_parseUnsignedLongJ_JLS(JNIEnv* env, const
    base::android::JavaRef<jstring>& p0) __attribute__ ((unused));
static jlong Java_Long_parseUnsignedLongJ_JLS(JNIEnv* env, const
    base::android::JavaRef<jstring>& p0) {
  CHECK_CLAZZ(env, java_lang_Long_clazz(env),
      java_lang_Long_clazz(env), 0);
  jmethodID method_id =
      base::android::MethodID::LazyGet<
      base::android::MethodID::TYPE_STATIC>(
      env, java_lang_Long_clazz(env),
      "parseUnsignedLong",
      "(Ljava/lang/String;)J",
      &g_java_lang_Long_parseUnsignedLongJ_JLS);

  jlong ret =
      env->CallStaticLongMethod(java_lang_Long_clazz(env),
          method_id, p0.obj());
  jni_generator::CheckException(env);
  return ret;
}

static base::subtle::AtomicWord g_java_lang_Long_valueOfJLLO_JLS_I = 0;
static base::android::ScopedJavaLocalRef<jobject>
    Java_Long_valueOfJLLO_JLS_I(JNIEnv* env, const
    base::android::JavaRef<jstring>& p0,
    JniIntWrapper p1) __attribute__ ((unused));
static base::android::ScopedJavaLocalRef<jobject>
    Java_Long_valueOfJLLO_JLS_I(JNIEnv* env, const
    base::android::JavaRef<jstring>& p0,
    JniIntWrapper p1) {
  CHECK_CLAZZ(env, java_lang_Long_clazz(env),
      java_lang_Long_clazz(env), NULL);
  jmethodID method_id =
      base::android::MethodID::LazyGet<
      base::android::MethodID::TYPE_STATIC>(
      env, java_lang_Long_clazz(env),
      "valueOf",
      "(Ljava/lang/String;I)Ljava/lang/Long;",
      &g_java_lang_Long_valueOfJLLO_JLS_I);

  jobject ret =
      env->CallStaticObjectMethod(java_lang_Long_clazz(env),
          method_id, p0.obj(), as_jint(p1));
  jni_generator::CheckException(env);
  return base::android::ScopedJavaLocalRef<jobject>(env, ret);
}

static base::subtle::AtomicWord g_java_lang_Long_valueOfJLLO_JLS = 0;
static base::android::ScopedJavaLocalRef<jobject>
    Java_Long_valueOfJLLO_JLS(JNIEnv* env, const
    base::android::JavaRef<jstring>& p0) __attribute__ ((unused));
static base::android::ScopedJavaLocalRef<jobject>
    Java_Long_valueOfJLLO_JLS(JNIEnv* env, const
    base::android::JavaRef<jstring>& p0) {
  CHECK_CLAZZ(env, java_lang_Long_clazz(env),
      java_lang_Long_clazz(env), NULL);
  jmethodID method_id =
      base::android::MethodID::LazyGet<
      base::android::MethodID::TYPE_STATIC>(
      env, java_lang_Long_clazz(env),
      "valueOf",
      "(Ljava/lang/String;)Ljava/lang/Long;",
      &g_java_lang_Long_valueOfJLLO_JLS);

  jobject ret =
      env->CallStaticObjectMethod(java_lang_Long_clazz(env),
          method_id, p0.obj());
  jni_generator::CheckException(env);
  return base::android::ScopedJavaLocalRef<jobject>(env, ret);
}

static base::subtle::AtomicWord g_java_lang_Long_valueOfJLLO_J = 0;
static base::android::ScopedJavaLocalRef<jobject>
    Java_Long_valueOfJLLO_J(JNIEnv* env, jlong p0) __attribute__ ((unused));
static base::android::ScopedJavaLocalRef<jobject>
    Java_Long_valueOfJLLO_J(JNIEnv* env, jlong p0) {
  CHECK_CLAZZ(env, java_lang_Long_clazz(env),
      java_lang_Long_clazz(env), NULL);
  jmethodID method_id =
      base::android::MethodID::LazyGet<
      base::android::MethodID::TYPE_STATIC>(
      env, java_lang_Long_clazz(env),
      "valueOf",
      "(J)Ljava/lang/Long;",
      &g_java_lang_Long_valueOfJLLO_J);

  jobject ret =
      env->CallStaticObjectMethod(java_lang_Long_clazz(env),
          method_id, p0);
  jni_generator::CheckException(env);
  return base::android::ScopedJavaLocalRef<jobject>(env, ret);
}

static base::subtle::AtomicWord g_java_lang_Long_decode = 0;
static base::android::ScopedJavaLocalRef<jobject> Java_Long_decode(JNIEnv* env,
    const base::android::JavaRef<jstring>& p0) __attribute__ ((unused));
static base::android::ScopedJavaLocalRef<jobject> Java_Long_decode(JNIEnv* env,
    const base::android::JavaRef<jstring>& p0) {
  CHECK_CLAZZ(env, java_lang_Long_clazz(env),
      java_lang_Long_clazz(env), NULL);
  jmethodID method_id =
      base::android::MethodID::LazyGet<
      base::android::MethodID::TYPE_STATIC>(
      env, java_lang_Long_clazz(env),
      "decode",
      "(Ljava/lang/String;)Ljava/lang/Long;",
      &g_java_lang_Long_decode);

  jobject ret =
      env->CallStaticObjectMethod(java_lang_Long_clazz(env),
          method_id, p0.obj());
  jni_generator::CheckException(env);
  return base::android::ScopedJavaLocalRef<jobject>(env, ret);
}

static base::subtle::AtomicWord g_java_lang_Long_byteValue = 0;
static jbyte Java_Long_byteValue(JNIEnv* env, const
    base::android::JavaRef<jobject>& obj) __attribute__ ((unused));
static jbyte Java_Long_byteValue(JNIEnv* env, const
    base::android::JavaRef<jobject>& obj) {
  CHECK_CLAZZ(env, obj.obj(),
      java_lang_Long_clazz(env), 0);
  jmethodID method_id =
      base::android::MethodID::LazyGet<
      base::android::MethodID::TYPE_INSTANCE>(
      env, java_lang_Long_clazz(env),
      "byteValue",
      "()B",
      &g_java_lang_Long_byteValue);

  jbyte ret =
      env->CallByteMethod(obj.obj(),
          method_id);
  jni_generator::CheckException(env);
  return ret;
}

static base::subtle::AtomicWord g_java_lang_Long_shortValue = 0;
static jshort Java_Long_shortValue(JNIEnv* env, const
    base::android::JavaRef<jobject>& obj) __attribute__ ((unused));
static jshort Java_Long_shortValue(JNIEnv* env, const
    base::android::JavaRef<jobject>& obj) {
  CHECK_CLAZZ(env, obj.obj(),
      java_lang_Long_clazz(env), 0);
  jmethodID method_id =
      base::android::MethodID::LazyGet<
      base::android::MethodID::TYPE_INSTANCE>(
      env, java_lang_Long_clazz(env),
      "shortValue",
      "()S",
      &g_java_lang_Long_shortValue);

  jshort ret =
      env->CallShortMethod(obj.obj(),
          method_id);
  jni_generator::CheckException(env);
  return ret;
}

static base::subtle::AtomicWord g_java_lang_Long_intValue = 0;
static jint Java_Long_intValue(JNIEnv* env, const
    base::android::JavaRef<jobject>& obj) __attribute__ ((unused));
static jint Java_Long_intValue(JNIEnv* env, const
    base::android::JavaRef<jobject>& obj) {
  CHECK_CLAZZ(env, obj.obj(),
      java_lang_Long_clazz(env), 0);
  jmethodID method_id =
      base::android::MethodID::LazyGet<
      base::android::MethodID::TYPE_INSTANCE>(
      env, java_lang_Long_clazz(env),
      "intValue",
      "()I",
      &g_java_lang_Long_intValue);

  jint ret =
      env->CallIntMethod(obj.obj(),
          method_id);
  jni_generator::CheckException(env);
  return ret;
}

static base::subtle::AtomicWord g_java_lang_Long_longValue = 0;
static jlong Java_Long_longValue(JNIEnv* env, const
    base::android::JavaRef<jobject>& obj) __attribute__ ((unused));
static jlong Java_Long_longValue(JNIEnv* env, const
    base::android::JavaRef<jobject>& obj) {
  CHECK_CLAZZ(env, obj.obj(),
      java_lang_Long_clazz(env), 0);
  jmethodID method_id =
      base::android::MethodID::LazyGet<
      base::android::MethodID::TYPE_INSTANCE>(
      env, java_lang_Long_clazz(env),
      "longValue",
      "()J",
      &g_java_lang_Long_longValue);

  jlong ret =
      env->CallLongMethod(obj.obj(),
          method_id);
  jni_generator::CheckException(env);
  return ret;
}

static base::subtle::AtomicWord g_java_lang_Long_floatValue = 0;
static jfloat Java_Long_floatValue(JNIEnv* env, const
    base::android::JavaRef<jobject>& obj) __attribute__ ((unused));
static jfloat Java_Long_floatValue(JNIEnv* env, const
    base::android::JavaRef<jobject>& obj) {
  CHECK_CLAZZ(env, obj.obj(),
      java_lang_Long_clazz(env), 0);
  jmethodID method_id =
      base::android::MethodID::LazyGet<
      base::android::MethodID::TYPE_INSTANCE>(
      env, java_lang_Long_clazz(env),
      "floatValue",
      "()F",
      &g_java_lang_Long_floatValue);

  jfloat ret =
      env->CallFloatMethod(obj.obj(),
          method_id);
  jni_generator::CheckException(env);
  return ret;
}

static base::subtle::AtomicWord g_java_lang_Long_doubleValue = 0;
static jdouble Java_Long_doubleValue(JNIEnv* env, const
    base::android::JavaRef<jobject>& obj) __attribute__ ((unused));
static jdouble Java_Long_doubleValue(JNIEnv* env, const
    base::android::JavaRef<jobject>& obj) {
  CHECK_CLAZZ(env, obj.obj(),
      java_lang_Long_clazz(env), 0);
  jmethodID method_id =
      base::android::MethodID::LazyGet<
      base::android::MethodID::TYPE_INSTANCE>(
      env, java_lang_Long_clazz(env),
      "doubleValue",
      "()D",
      &g_java_lang_Long_doubleValue);

  jdouble ret =
      env->CallDoubleMethod(obj.obj(),
          method_id);
  jni_generator::CheckException(env);
  return ret;
}

static base::subtle::AtomicWord g_java_lang_Long_toStringJLS = 0;
static base::android::ScopedJavaLocalRef<jstring> Java_Long_toStringJLS(JNIEnv*
    env, const base::android::JavaRef<jobject>& obj) __attribute__ ((unused));
static base::android::ScopedJavaLocalRef<jstring> Java_Long_toStringJLS(JNIEnv*
    env, const base::android::JavaRef<jobject>& obj) {
  CHECK_CLAZZ(env, obj.obj(),
      java_lang_Long_clazz(env), NULL);
  jmethodID method_id =
      base::android::MethodID::LazyGet<
      base::android::MethodID::TYPE_INSTANCE>(
      env, java_lang_Long_clazz(env),
      "toString",
      "()Ljava/lang/String;",
      &g_java_lang_Long_toStringJLS);

  jstring ret =
      static_cast<jstring>(env->CallObjectMethod(obj.obj(),
          method_id));
  jni_generator::CheckException(env);
  return base::android::ScopedJavaLocalRef<jstring>(env, ret);
}

static base::subtle::AtomicWord g_java_lang_Long_hashCodeI = 0;
static jint Java_Long_hashCodeI(JNIEnv* env, const
    base::android::JavaRef<jobject>& obj) __attribute__ ((unused));
static jint Java_Long_hashCodeI(JNIEnv* env, const
    base::android::JavaRef<jobject>& obj) {
  CHECK_CLAZZ(env, obj.obj(),
      java_lang_Long_clazz(env), 0);
  jmethodID method_id =
      base::android::MethodID::LazyGet<
      base::android::MethodID::TYPE_INSTANCE>(
      env, java_lang_Long_clazz(env),
      "hashCode",
      "()I",
      &g_java_lang_Long_hashCodeI);

  jint ret =
      env->CallIntMethod(obj.obj(),
          method_id);
  jni_generator::CheckException(env);
  return ret;
}

static base::subtle::AtomicWord g_java_lang_Long_hashCodeI_J = 0;
static jint Java_Long_hashCodeI_J(JNIEnv* env, jlong p0) __attribute__
    ((unused));
static jint Java_Long_hashCodeI_J(JNIEnv* env, jlong p0) {
  CHECK_CLAZZ(env, java_lang_Long_clazz(env),
      java_lang_Long_clazz(env), 0);
  jmethodID method_id =
      base::android::MethodID::LazyGet<
      base::android::MethodID::TYPE_STATIC>(
      env, java_lang_Long_clazz(env),
      "hashCode",
      "(J)I",
      &g_java_lang_Long_hashCodeI_J);

  jint ret =
      env->CallStaticIntMethod(java_lang_Long_clazz(env),
          method_id, p0);
  jni_generator::CheckException(env);
  return ret;
}

static base::subtle::AtomicWord g_java_lang_Long_equals = 0;
static jboolean Java_Long_equals(JNIEnv* env, const
    base::android::JavaRef<jobject>& obj, const base::android::JavaRef<jobject>&
    p0) __attribute__ ((unused));
static jboolean Java_Long_equals(JNIEnv* env, const
    base::android::JavaRef<jobject>& obj, const base::android::JavaRef<jobject>&
    p0) {
  CHECK_CLAZZ(env, obj.obj(),
      java_lang_Long_clazz(env), false);
  jmethodID method_id =
      base::android::MethodID::LazyGet<
      base::android::MethodID::TYPE_INSTANCE>(
      env, java_lang_Long_clazz(env),
      "equals",
      "(Ljava/lang/Object;)Z",
      &g_java_lang_Long_equals);

  jboolean ret =
      env->CallBooleanMethod(obj.obj(),
          method_id, p0.obj());
  jni_generator::CheckException(env);
  return ret;
}

static base::subtle::AtomicWord g_java_lang_Long_getLongJLLO_JLS = 0;
static base::android::ScopedJavaLocalRef<jobject>
    Java_Long_getLongJLLO_JLS(JNIEnv* env, const
    base::android::JavaRef<jstring>& p0) __attribute__ ((unused));
static base::android::ScopedJavaLocalRef<jobject>
    Java_Long_getLongJLLO_JLS(JNIEnv* env, const
    base::android::JavaRef<jstring>& p0) {
  CHECK_CLAZZ(env, java_lang_Long_clazz(env),
      java_lang_Long_clazz(env), NULL);
  jmethodID method_id =
      base::android::MethodID::LazyGet<
      base::android::MethodID::TYPE_STATIC>(
      env, java_lang_Long_clazz(env),
      "getLong",
      "(Ljava/lang/String;)Ljava/lang/Long;",
      &g_java_lang_Long_getLongJLLO_JLS);

  jobject ret =
      env->CallStaticObjectMethod(java_lang_Long_clazz(env),
          method_id, p0.obj());
  jni_generator::CheckException(env);
  return base::android::ScopedJavaLocalRef<jobject>(env, ret);
}

static base::subtle::AtomicWord g_java_lang_Long_getLongJLLO_JLS_J = 0;
static base::android::ScopedJavaLocalRef<jobject>
    Java_Long_getLongJLLO_JLS_J(JNIEnv* env, const
    base::android::JavaRef<jstring>& p0,
    jlong p1) __attribute__ ((unused));
static base::android::ScopedJavaLocalRef<jobject>
    Java_Long_getLongJLLO_JLS_J(JNIEnv* env, const
    base::android::JavaRef<jstring>& p0,
    jlong p1) {
  CHECK_CLAZZ(env, java_lang_Long_clazz(env),
      java_lang_Long_clazz(env), NULL);
  jmethodID method_id =
      base::android::MethodID::LazyGet<
      base::android::MethodID::TYPE_STATIC>(
      env, java_lang_Long_clazz(env),
      "getLong",
      "(Ljava/lang/String;J)Ljava/lang/Long;",
      &g_java_lang_Long_getLongJLLO_JLS_J);

  jobject ret =
      env->CallStaticObjectMethod(java_lang_Long_clazz(env),
          method_id, p0.obj(), p1);
  jni_generator::CheckException(env);
  return base::android::ScopedJavaLocalRef<jobject>(env, ret);
}

static base::subtle::AtomicWord g_java_lang_Long_getLongJLLO_JLS_JLLO = 0;
static base::android::ScopedJavaLocalRef<jobject>
    Java_Long_getLongJLLO_JLS_JLLO(JNIEnv* env, const
    base::android::JavaRef<jstring>& p0,
    const base::android::JavaRef<jobject>& p1) __attribute__ ((unused));
static base::android::ScopedJavaLocalRef<jobject>
    Java_Long_getLongJLLO_JLS_JLLO(JNIEnv* env, const
    base::android::JavaRef<jstring>& p0,
    const base::android::JavaRef<jobject>& p1) {
  CHECK_CLAZZ(env, java_lang_Long_clazz(env),
      java_lang_Long_clazz(env), NULL);
  jmethodID method_id =
      base::android::MethodID::LazyGet<
      base::android::MethodID::TYPE_STATIC>(
      env, java_lang_Long_clazz(env),
      "getLong",
      "(Ljava/lang/String;Ljava/lang/Long;)Ljava/lang/Long;",
      &g_java_lang_Long_getLongJLLO_JLS_JLLO);

  jobject ret =
      env->CallStaticObjectMethod(java_lang_Long_clazz(env),
          method_id, p0.obj(), p1.obj());
  jni_generator::CheckException(env);
  return base::android::ScopedJavaLocalRef<jobject>(env, ret);
}

static base::subtle::AtomicWord g_java_lang_Long_compareToI_JLLO = 0;
static jint Java_Long_compareToI_JLLO(JNIEnv* env, const
    base::android::JavaRef<jobject>& obj, const base::android::JavaRef<jobject>&
    p0) __attribute__ ((unused));
static jint Java_Long_compareToI_JLLO(JNIEnv* env, const
    base::android::JavaRef<jobject>& obj, const base::android::JavaRef<jobject>&
    p0) {
  CHECK_CLAZZ(env, obj.obj(),
      java_lang_Long_clazz(env), 0);
  jmethodID method_id =
      base::android::MethodID::LazyGet<
      base::android::MethodID::TYPE_INSTANCE>(
      env, java_lang_Long_clazz(env),
      "compareTo",
      "(Ljava/lang/Long;)I",
      &g_java_lang_Long_compareToI_JLLO);

  jint ret =
      env->CallIntMethod(obj.obj(),
          method_id, p0.obj());
  jni_generator::CheckException(env);
  return ret;
}

static base::subtle::AtomicWord g_java_lang_Long_compare = 0;
static jint Java_Long_compare(JNIEnv* env, jlong p0,
    jlong p1) __attribute__ ((unused));
static jint Java_Long_compare(JNIEnv* env, jlong p0,
    jlong p1) {
  CHECK_CLAZZ(env, java_lang_Long_clazz(env),
      java_lang_Long_clazz(env), 0);
  jmethodID method_id =
      base::android::MethodID::LazyGet<
      base::android::MethodID::TYPE_STATIC>(
      env, java_lang_Long_clazz(env),
      "compare",
      "(JJ)I",
      &g_java_lang_Long_compare);

  jint ret =
      env->CallStaticIntMethod(java_lang_Long_clazz(env),
          method_id, p0, p1);
  jni_generator::CheckException(env);
  return ret;
}

static base::subtle::AtomicWord g_java_lang_Long_compareUnsigned = 0;
static jint Java_Long_compareUnsigned(JNIEnv* env, jlong p0,
    jlong p1) __attribute__ ((unused));
static jint Java_Long_compareUnsigned(JNIEnv* env, jlong p0,
    jlong p1) {
  CHECK_CLAZZ(env, java_lang_Long_clazz(env),
      java_lang_Long_clazz(env), 0);
  jmethodID method_id =
      base::android::MethodID::LazyGet<
      base::android::MethodID::TYPE_STATIC>(
      env, java_lang_Long_clazz(env),
      "compareUnsigned",
      "(JJ)I",
      &g_java_lang_Long_compareUnsigned);

  jint ret =
      env->CallStaticIntMethod(java_lang_Long_clazz(env),
          method_id, p0, p1);
  jni_generator::CheckException(env);
  return ret;
}

static base::subtle::AtomicWord g_java_lang_Long_divideUnsigned = 0;
static jlong Java_Long_divideUnsigned(JNIEnv* env, jlong p0,
    jlong p1) __attribute__ ((unused));
static jlong Java_Long_divideUnsigned(JNIEnv* env, jlong p0,
    jlong p1) {
  CHECK_CLAZZ(env, java_lang_Long_clazz(env),
      java_lang_Long_clazz(env), 0);
  jmethodID method_id =
      base::android::MethodID::LazyGet<
      base::android::MethodID::TYPE_STATIC>(
      env, java_lang_Long_clazz(env),
      "divideUnsigned",
      "(JJ)J",
      &g_java_lang_Long_divideUnsigned);

  jlong ret =
      env->CallStaticLongMethod(java_lang_Long_clazz(env),
          method_id, p0, p1);
  jni_generator::CheckException(env);
  return ret;
}

static base::subtle::AtomicWord g_java_lang_Long_remainderUnsigned = 0;
static jlong Java_Long_remainderUnsigned(JNIEnv* env, jlong p0,
    jlong p1) __attribute__ ((unused));
static jlong Java_Long_remainderUnsigned(JNIEnv* env, jlong p0,
    jlong p1) {
  CHECK_CLAZZ(env, java_lang_Long_clazz(env),
      java_lang_Long_clazz(env), 0);
  jmethodID method_id =
      base::android::MethodID::LazyGet<
      base::android::MethodID::TYPE_STATIC>(
      env, java_lang_Long_clazz(env),
      "remainderUnsigned",
      "(JJ)J",
      &g_java_lang_Long_remainderUnsigned);

  jlong ret =
      env->CallStaticLongMethod(java_lang_Long_clazz(env),
          method_id, p0, p1);
  jni_generator::CheckException(env);
  return ret;
}

static base::subtle::AtomicWord g_java_lang_Long_highestOneBit = 0;
static jlong Java_Long_highestOneBit(JNIEnv* env, jlong p0) __attribute__
    ((unused));
static jlong Java_Long_highestOneBit(JNIEnv* env, jlong p0) {
  CHECK_CLAZZ(env, java_lang_Long_clazz(env),
      java_lang_Long_clazz(env), 0);
  jmethodID method_id =
      base::android::MethodID::LazyGet<
      base::android::MethodID::TYPE_STATIC>(
      env, java_lang_Long_clazz(env),
      "highestOneBit",
      "(J)J",
      &g_java_lang_Long_highestOneBit);

  jlong ret =
      env->CallStaticLongMethod(java_lang_Long_clazz(env),
          method_id, p0);
  jni_generator::CheckException(env);
  return ret;
}

static base::subtle::AtomicWord g_java_lang_Long_lowestOneBit = 0;
static jlong Java_Long_lowestOneBit(JNIEnv* env, jlong p0) __attribute__
    ((unused));
static jlong Java_Long_lowestOneBit(JNIEnv* env, jlong p0) {
  CHECK_CLAZZ(env, java_lang_Long_clazz(env),
      java_lang_Long_clazz(env), 0);
  jmethodID method_id =
      base::android::MethodID::LazyGet<
      base::android::MethodID::TYPE_STATIC>(
      env, java_lang_Long_clazz(env),
      "lowestOneBit",
      "(J)J",
      &g_java_lang_Long_lowestOneBit);

  jlong ret =
      env->CallStaticLongMethod(java_lang_Long_clazz(env),
          method_id, p0);
  jni_generator::CheckException(env);
  return ret;
}

static base::subtle::AtomicWord g_java_lang_Long_numberOfLeadingZeros = 0;
static jint Java_Long_numberOfLeadingZeros(JNIEnv* env, jlong p0) __attribute__
    ((unused));
static jint Java_Long_numberOfLeadingZeros(JNIEnv* env, jlong p0) {
  CHECK_CLAZZ(env, java_lang_Long_clazz(env),
      java_lang_Long_clazz(env), 0);
  jmethodID method_id =
      base::android::MethodID::LazyGet<
      base::android::MethodID::TYPE_STATIC>(
      env, java_lang_Long_clazz(env),
      "numberOfLeadingZeros",
      "(J)I",
      &g_java_lang_Long_numberOfLeadingZeros);

  jint ret =
      env->CallStaticIntMethod(java_lang_Long_clazz(env),
          method_id, p0);
  jni_generator::CheckException(env);
  return ret;
}

static base::subtle::AtomicWord g_java_lang_Long_numberOfTrailingZeros = 0;
static jint Java_Long_numberOfTrailingZeros(JNIEnv* env, jlong p0) __attribute__
    ((unused));
static jint Java_Long_numberOfTrailingZeros(JNIEnv* env, jlong p0) {
  CHECK_CLAZZ(env, java_lang_Long_clazz(env),
      java_lang_Long_clazz(env), 0);
  jmethodID method_id =
      base::android::MethodID::LazyGet<
      base::android::MethodID::TYPE_STATIC>(
      env, java_lang_Long_clazz(env),
      "numberOfTrailingZeros",
      "(J)I",
      &g_java_lang_Long_numberOfTrailingZeros);

  jint ret =
      env->CallStaticIntMethod(java_lang_Long_clazz(env),
          method_id, p0);
  jni_generator::CheckException(env);
  return ret;
}

static base::subtle::AtomicWord g_java_lang_Long_bitCount = 0;
static jint Java_Long_bitCount(JNIEnv* env, jlong p0) __attribute__ ((unused));
static jint Java_Long_bitCount(JNIEnv* env, jlong p0) {
  CHECK_CLAZZ(env, java_lang_Long_clazz(env),
      java_lang_Long_clazz(env), 0);
  jmethodID method_id =
      base::android::MethodID::LazyGet<
      base::android::MethodID::TYPE_STATIC>(
      env, java_lang_Long_clazz(env),
      "bitCount",
      "(J)I",
      &g_java_lang_Long_bitCount);

  jint ret =
      env->CallStaticIntMethod(java_lang_Long_clazz(env),
          method_id, p0);
  jni_generator::CheckException(env);
  return ret;
}

static base::subtle::AtomicWord g_java_lang_Long_rotateLeft = 0;
static jlong Java_Long_rotateLeft(JNIEnv* env, jlong p0,
    JniIntWrapper p1) __attribute__ ((unused));
static jlong Java_Long_rotateLeft(JNIEnv* env, jlong p0,
    JniIntWrapper p1) {
  CHECK_CLAZZ(env, java_lang_Long_clazz(env),
      java_lang_Long_clazz(env), 0);
  jmethodID method_id =
      base::android::MethodID::LazyGet<
      base::android::MethodID::TYPE_STATIC>(
      env, java_lang_Long_clazz(env),
      "rotateLeft",
      "(JI)J",
      &g_java_lang_Long_rotateLeft);

  jlong ret =
      env->CallStaticLongMethod(java_lang_Long_clazz(env),
          method_id, p0, as_jint(p1));
  jni_generator::CheckException(env);
  return ret;
}

static base::subtle::AtomicWord g_java_lang_Long_rotateRight = 0;
static jlong Java_Long_rotateRight(JNIEnv* env, jlong p0,
    JniIntWrapper p1) __attribute__ ((unused));
static jlong Java_Long_rotateRight(JNIEnv* env, jlong p0,
    JniIntWrapper p1) {
  CHECK_CLAZZ(env, java_lang_Long_clazz(env),
      java_lang_Long_clazz(env), 0);
  jmethodID method_id =
      base::android::MethodID::LazyGet<
      base::android::MethodID::TYPE_STATIC>(
      env, java_lang_Long_clazz(env),
      "rotateRight",
      "(JI)J",
      &g_java_lang_Long_rotateRight);

  jlong ret =
      env->CallStaticLongMethod(java_lang_Long_clazz(env),
          method_id, p0, as_jint(p1));
  jni_generator::CheckException(env);
  return ret;
}

static base::subtle::AtomicWord g_java_lang_Long_reverse = 0;
static jlong Java_Long_reverse(JNIEnv* env, jlong p0) __attribute__ ((unused));
static jlong Java_Long_reverse(JNIEnv* env, jlong p0) {
  CHECK_CLAZZ(env, java_lang_Long_clazz(env),
      java_lang_Long_clazz(env), 0);
  jmethodID method_id =
      base::android::MethodID::LazyGet<
      base::android::MethodID::TYPE_STATIC>(
      env, java_lang_Long_clazz(env),
      "reverse",
      "(J)J",
      &g_java_lang_Long_reverse);

  jlong ret =
      env->CallStaticLongMethod(java_lang_Long_clazz(env),
          method_id, p0);
  jni_generator::CheckException(env);
  return ret;
}

static base::subtle::AtomicWord g_java_lang_Long_signum = 0;
static jint Java_Long_signum(JNIEnv* env, jlong p0) __attribute__ ((unused));
static jint Java_Long_signum(JNIEnv* env, jlong p0) {
  CHECK_CLAZZ(env, java_lang_Long_clazz(env),
      java_lang_Long_clazz(env), 0);
  jmethodID method_id =
      base::android::MethodID::LazyGet<
      base::android::MethodID::TYPE_STATIC>(
      env, java_lang_Long_clazz(env),
      "signum",
      "(J)I",
      &g_java_lang_Long_signum);

  jint ret =
      env->CallStaticIntMethod(java_lang_Long_clazz(env),
          method_id, p0);
  jni_generator::CheckException(env);
  return ret;
}

static base::subtle::AtomicWord g_java_lang_Long_reverseBytes = 0;
static jlong Java_Long_reverseBytes(JNIEnv* env, jlong p0) __attribute__
    ((unused));
static jlong Java_Long_reverseBytes(JNIEnv* env, jlong p0) {
  CHECK_CLAZZ(env, java_lang_Long_clazz(env),
      java_lang_Long_clazz(env), 0);
  jmethodID method_id =
      base::android::MethodID::LazyGet<
      base::android::MethodID::TYPE_STATIC>(
      env, java_lang_Long_clazz(env),
      "reverseBytes",
      "(J)J",
      &g_java_lang_Long_reverseBytes);

  jlong ret =
      env->CallStaticLongMethod(java_lang_Long_clazz(env),
          method_id, p0);
  jni_generator::CheckException(env);
  return ret;
}

static base::subtle::AtomicWord g_java_lang_Long_sum = 0;
static jlong Java_Long_sum(JNIEnv* env, jlong p0,
    jlong p1) __attribute__ ((unused));
static jlong Java_Long_sum(JNIEnv* env, jlong p0,
    jlong p1) {
  CHECK_CLAZZ(env, java_lang_Long_clazz(env),
      java_lang_Long_clazz(env), 0);
  jmethodID method_id =
      base::android::MethodID::LazyGet<
      base::android::MethodID::TYPE_STATIC>(
      env, java_lang_Long_clazz(env),
      "sum",
      "(JJ)J",
      &g_java_lang_Long_sum);

  jlong ret =
      env->CallStaticLongMethod(java_lang_Long_clazz(env),
          method_id, p0, p1);
  jni_generator::CheckException(env);
  return ret;
}

static base::subtle::AtomicWord g_java_lang_Long_max = 0;
static jlong Java_Long_max(JNIEnv* env, jlong p0,
    jlong p1) __attribute__ ((unused));
static jlong Java_Long_max(JNIEnv* env, jlong p0,
    jlong p1) {
  CHECK_CLAZZ(env, java_lang_Long_clazz(env),
      java_lang_Long_clazz(env), 0);
  jmethodID method_id =
      base::android::MethodID::LazyGet<
      base::android::MethodID::TYPE_STATIC>(
      env, java_lang_Long_clazz(env),
      "max",
      "(JJ)J",
      &g_java_lang_Long_max);

  jlong ret =
      env->CallStaticLongMethod(java_lang_Long_clazz(env),
          method_id, p0, p1);
  jni_generator::CheckException(env);
  return ret;
}

static base::subtle::AtomicWord g_java_lang_Long_min = 0;
static jlong Java_Long_min(JNIEnv* env, jlong p0,
    jlong p1) __attribute__ ((unused));
static jlong Java_Long_min(JNIEnv* env, jlong p0,
    jlong p1) {
  CHECK_CLAZZ(env, java_lang_Long_clazz(env),
      java_lang_Long_clazz(env), 0);
  jmethodID method_id =
      base::android::MethodID::LazyGet<
      base::android::MethodID::TYPE_STATIC>(
      env, java_lang_Long_clazz(env),
      "min",
      "(JJ)J",
      &g_java_lang_Long_min);

  jlong ret =
      env->CallStaticLongMethod(java_lang_Long_clazz(env),
          method_id, p0, p1);
  jni_generator::CheckException(env);
  return ret;
}

static base::subtle::AtomicWord g_java_lang_Long_compareToI_JLO = 0;
static jint Java_Long_compareToI_JLO(JNIEnv* env, const
    base::android::JavaRef<jobject>& obj, const base::android::JavaRef<jobject>&
    p0) __attribute__ ((unused));
static jint Java_Long_compareToI_JLO(JNIEnv* env, const
    base::android::JavaRef<jobject>& obj, const base::android::JavaRef<jobject>&
    p0) {
  CHECK_CLAZZ(env, obj.obj(),
      java_lang_Long_clazz(env), 0);
  jmethodID method_id =
      base::android::MethodID::LazyGet<
      base::android::MethodID::TYPE_INSTANCE>(
      env, java_lang_Long_clazz(env),
      "compareTo",
      "(Ljava/lang/Object;)I",
      &g_java_lang_Long_compareToI_JLO);

  jint ret =
      env->CallIntMethod(obj.obj(),
          method_id, p0.obj());
  jni_generator::CheckException(env);
  return ret;
}

static base::subtle::AtomicWord g_java_lang_Long_ConstructorJLLO_J = 0;
static base::android::ScopedJavaLocalRef<jobject>
    Java_Long_ConstructorJLLO_J(JNIEnv* env, jlong p0) __attribute__ ((unused));
static base::android::ScopedJavaLocalRef<jobject>
    Java_Long_ConstructorJLLO_J(JNIEnv* env, jlong p0) {
  CHECK_CLAZZ(env, java_lang_Long_clazz(env),
      java_lang_Long_clazz(env), NULL);
  jmethodID method_id =
      base::android::MethodID::LazyGet<
      base::android::MethodID::TYPE_INSTANCE>(
      env, java_lang_Long_clazz(env),
      "<init>",
      "(J)V",
      &g_java_lang_Long_ConstructorJLLO_J);

  jobject ret =
      env->NewObject(java_lang_Long_clazz(env),
          method_id, p0);
  jni_generator::CheckException(env);
  return base::android::ScopedJavaLocalRef<jobject>(env, ret);
}

static base::subtle::AtomicWord g_java_lang_Long_ConstructorJLLO_JLS = 0;
static base::android::ScopedJavaLocalRef<jobject>
    Java_Long_ConstructorJLLO_JLS(JNIEnv* env, const
    base::android::JavaRef<jstring>& p0) __attribute__ ((unused));
static base::android::ScopedJavaLocalRef<jobject>
    Java_Long_ConstructorJLLO_JLS(JNIEnv* env, const
    base::android::JavaRef<jstring>& p0) {
  CHECK_CLAZZ(env, java_lang_Long_clazz(env),
      java_lang_Long_clazz(env), NULL);
  jmethodID method_id =
      base::android::MethodID::LazyGet<
      base::android::MethodID::TYPE_INSTANCE>(
      env, java_lang_Long_clazz(env),
      "<init>",
      "(Ljava/lang/String;)V",
      &g_java_lang_Long_ConstructorJLLO_JLS);

  jobject ret =
      env->NewObject(java_lang_Long_clazz(env),
          method_id, p0.obj());
  jni_generator::CheckException(env);
  return base::android::ScopedJavaLocalRef<jobject>(env, ret);
}

}  // namespace JNI_Long

#endif  // java_lang_Long_JNI
