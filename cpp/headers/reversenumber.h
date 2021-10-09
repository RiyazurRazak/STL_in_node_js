#include "napi.h"

namespace reversenumber
{

    long long Reverse(long long);
    Napi::Object Init(Napi::Env env, Napi::Object exports);
    Napi::Value ReverseNumberWrap(const Napi::CallbackInfo &info);
}