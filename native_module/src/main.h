#ifndef MAIN_H
#define MAIN_H

#include <napi.h>
#include <iostream>
#include <algorithm>
#include <string>

#ifdef _WIN32
#include <olectl.h>
#endif

using namespace std;
namespace ideCAD
{
    std::string checksum(std::u16string filename);
    Napi::String checksumWrapped(const Napi::CallbackInfo &info);
    // Export API
    Napi::Object Init(Napi::Env env, Napi::Object exports);
    NODE_API_MODULE(addon, Init)
}

#endif // MAIN_H