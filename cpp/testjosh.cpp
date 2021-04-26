//
// Created by Joshua Griffin on 24/04/21.
//

#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_testsqlite_MainActivity_stringFromJoshTest(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from JoshTEST";
    return env->NewStringUTF(hello.c_str());
}extern "C"
JNIEXPORT jstring JNICALL
Java_com_testsqlite_MainActivity_stringFromJoshTest(JNIEnv *env, jobject thiz) {
    // TODO: implement stringFromJoshTest()
    std::string hello = "Hello from JoshTEST";
    return env->NewStringUTF(hello.c_str());
}