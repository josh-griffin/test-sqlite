//
// Created by Joshua Griffin on 24/04/21.
//

#include <jni.h>

#include <string>
#include <jsi/jsi.h>
#include <jsi/jsilib.h>
#include "sqlite_adapter.cpp"

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



void install(jsi::Runtime &jsiRuntime, const char *docPath)
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

     auto open = jsi::Function::createFromHostFunction(
             jsiRuntime,
             jsi::PropNameID::forAscii(jsiRuntime, "sequel_open"),
             1,
             [docPath](jsi::Runtime &rt, const jsi::Value &thisValue, const jsi::Value *args, size_t count) -> jsi::Value {
                 if (!args[0].isString())
                 {
                     jsi::detail::throwJSError(rt, "dbName must be a string");
                     return {};
                 }

                 string dbName = args[0].asString(rt).utf8(rt);

                 SequelResult result = sqlite_open(dbName, docPath);

                 if (result.type == SequelResultError)
                 {
                     jsi::detail::throwJSError(rt, result.message.c_str());
                     return {};
                 }

                 return move(result.value);
             });

    jsiRuntime.global().setProperty(jsiRuntime, "open", move(open));

}

extern "C" JNIEXPORT void
Java_com_testsqlite_SQLiteJSIModulePackage_nativeInit(JNIEnv *env, jclass thiz, jlong jsi, jstring docPath)
{
    auto runtime = reinterpret_cast<jsi::Runtime *>(jsi);
    if (runtime){
        jboolean isCopy;
        const char *docPathString = (env)->GetStringUTFChars(docPath, &isCopy);
        install(*runtime, docPathString);
    }

}