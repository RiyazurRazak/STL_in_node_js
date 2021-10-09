#include "../headers/reversenumber.h"

long long reversenumber::Reverse(long long value)
{
    long long reverseValue = 0;
    while (value != 0)
    {
        reverseValue = reverseValue * 10 + value % 10;
        value /= 10;
    }
    return reverseValue;
}

Napi::Value reversenumber::ReverseNumberWrap(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    long long input = info[0].As<Napi::Number>();
    return Napi::Number::New(env, reversenumber::Reverse(input));
}

Napi::Object reversenumber::Init(Napi::Env env, Napi::Object exports)
{
    exports.Set("reversenumber", Napi::Function::New(env, reversenumber::ReverseNumberWrap));
    return exports;
}