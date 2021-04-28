//
// Created by Joshua Griffin on 24/04/21.
//

#include <jni.h>

#include <string>
#include <jsi/jsi.h>
#include <jsi/jsilib.h>

using namespace std;
using namespace facebook;
using namespace jsi;


extern "C" JNIEXPORT jstring JNICALL
Java_com_example_testsqlite_MainActivity_stringFromJoshTest(
    JNIEnv *env,
    jobject /* this */)
{
    std::string hello = "Hello from JoshTEST";
    return env->NewStringUTF(hello.c_str());
}
extern "C" JNIEXPORT jstring JNICALL
Java_com_testsqlite_MainActivity_stringFromJoshTest(JNIEnv *env, jobject thiz)
{
    // TODO: implement stringFromJoshTest()
    std::string hello = "Hello from JoshTEST";
    return env->NewStringUTF(hello.c_str());
}



void install(jsi::Runtime &jsiRuntime)
{
    auto test = jsi::Function::createFromHostFunction(jsiRuntime,
                                                 jsi::PropNameID::forAscii(jsiRuntime,
                                                                      "test"),
                                                 0,
                                                 [](jsi::Runtime &runtime,
                                                    const jsi::Value &thisValue,
                                                    const jsi::Value *arguments,
                                                    size_t count) -> jsi::Value {
                                                     std::string hello = "Josh is cool!";
                                                     return jsi::String::createFromAscii(runtime, hello);
                                                 });

    jsiRuntime.global().setProperty(jsiRuntime, "test", move(test));
}

extern "C" JNIEXPORT void
Java_com_testsqlite_SQLiteJSIModulePackage_nativeInit(JNIEnv *env, jclass thiz, jlong jsi)
{
    auto runtime = reinterpret_cast<jsi::Runtime *>(jsi);
    if (runtime){

        install(*runtime);
    }

}