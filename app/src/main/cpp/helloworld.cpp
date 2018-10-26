//
// Created by haitendxia on 2018/10/25.
//

#include <android/log.h>
extern "C"
{
    char* print() {
        __android_log_print(ANDROID_LOG_INFO,"loadso_demo","I am in hello world!!");
        return "I am in hello world!!";
    }
}