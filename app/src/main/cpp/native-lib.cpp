#include <jni.h>
#include <string>
#include<android/log.h>

#ifndef LOG_TAG
#define LOG_TAG "HELLO_JNI"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG ,__VA_ARGS__) // 定义LOGD类型
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,LOG_TAG ,__VA_ARGS__) // 定义LOGI类型
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN,LOG_TAG ,__VA_ARGS__) // 定义LOGW类型
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,LOG_TAG ,__VA_ARGS__) // 定义LOGE类型
#define LOGF(...) __android_log_print(ANDROID_LOG_FATAL,LOG_TAG ,__VA_ARGS__) // 定义LOGF类型
#endif


jobject gThiz;


extern "C" {
JNIEXPORT jstring JNICALL
Java_com_wzq_ndk_MainActivity_stringFromJNI(JNIEnv *env, jobject jobject1) {

    gThiz = env->NewGlobalRef(jobject1);

    jclass jclass1 = env->GetObjectClass(jobject1);
    jmethodID jmethodId = env->GetMethodID(jclass1, "textJni", "(Ljava/lang/String;)V");
    jstring jstring1 = env->NewStringUTF("this is text String");
    env->CallVoidMethod(jobject1, jmethodId, jstring1);


///**
// * 抛出异常
// */
    jclass nullException = env->FindClass("java/lang/NullPointerException");
    if (nullException != nullptr) {
        return reinterpret_cast<jstring>(env->ThrowNew(nullException, "Null aaaaaaaaaaaa"));
    }


    jfieldID jfieldId = env->GetStaticFieldID(jclass1, "Companion",
                                              "Lcom/wzq/ndk/MainActivity$Companion;");

    jobject comjobject = env->GetStaticObjectField(jclass1, jfieldId);
    jclass CompanionClazz = env->GetObjectClass(comjobject);
    jmethodID jmethodId1 = env->GetMethodID(CompanionClazz, "staticTextJni",
                                            "(Ljava/lang/String;)V");
    jstring jstring2 = env->NewStringUTF("this is staticTextJni");
    env->CallVoidMethod(comjobject, jmethodId1, jstring2);
    env->DeleteGlobalRef(gThiz);
    return env->NewStringUTF("aaaa");
}
JNIEXPORT void JNICALL
Java_com_wzq_ndk_MainActivity_fileRead(JNIEnv *env, jobject thiz, jstring path, jstring path1) {

}
}
