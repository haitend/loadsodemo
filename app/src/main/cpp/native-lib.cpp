#include <jni.h>
#include <string>
#include <dlfcn.h>
void *handle = nullptr;
//函数指针
typedef char* (*CAC_FUNC)();
CAC_FUNC cac_func;

extern "C"
JNIEXPORT jstring

JNICALL
Java_com_demo_loadso_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject jobj) {
    std::string hello = "I am in jni!!";
    return env->NewStringUTF(hello.c_str());
}
extern "C"
JNIEXPORT jstring

JNICALL
Java_com_demo_loadso_MainActivity_loadHelloWorld(
        JNIEnv *env,
        jobject jobj,jstring soPath) {
    const char *path = env->GetStringUTFChars(soPath, 0);
    handle = dlopen(path, RTLD_LAZY);
    if (!handle) {
        env->ReleaseStringUTFChars(soPath, path);
        return env->NewStringUTF("load helloworld faild!!");
    }
    dlerror();
    cac_func = (CAC_FUNC)dlsym(handle, "print");
    char* result = cac_func();
    env->ReleaseStringUTFChars(soPath, path);
    return env->NewStringUTF(result);
}

extern "C"
JNIEXPORT jstring

JNICALL
Java_com_demo_loadso_MainActivity_unLoadHelloWorld(
        JNIEnv *env,
        jobject jobj) {
    std::string unload = "unload hello world!";
    if(handle != 0)
    {
        dlclose(handle);
        handle = 0;
    }
    return env->NewStringUTF(unload.c_str());
}
extern "C"
JNIEXPORT jstring

JNICALL
Java_com_demo_loadso_MainActivity_loadHelloColor(
        JNIEnv *env,
        jobject jobj,jstring soPath) {
    const char *path = env->GetStringUTFChars(soPath, 0);
    handle = dlopen(path, RTLD_LAZY);
    if (!handle) {
        env->ReleaseStringUTFChars(soPath, path);
        return env->NewStringUTF("load helloColor faild!!");
    }
    dlerror();
    cac_func = (CAC_FUNC)dlsym(handle, "print");
    char* result = cac_func();
    env->ReleaseStringUTFChars(soPath, path);
    return env->NewStringUTF(result);
}
extern "C"
JNIEXPORT jstring

JNICALL
Java_com_demo_loadso_MainActivity_unLoadHelloColor(
        JNIEnv *env,
        jobject jobj) {
    std::string unload = "unload hello color!";
    if(handle != 0)
    {
        dlclose(handle);
        handle = 0;
    }
    return env->NewStringUTF(unload.c_str());
}