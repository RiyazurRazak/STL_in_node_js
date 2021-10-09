#include "napi.h"
#include "../../headers/heap/wrapper.h"
#include "bits/stdc++.h"

Napi::FunctionReference HeapWrapper::constructor;

Napi::Object HeapWrapper::Init(Napi::Env env, Napi::Object exports)
{
    Napi::HandleScope scope(env);

    Napi::Function func = DefineClass(env, "heap", {
                                                       InstanceMethod("pop", &HeapWrapper::popWrap),
                                                   });

    constructor = Napi::Persistent(func);
    constructor.SuppressDestruct();

    exports.Set("heap", func);
    return exports;
}

HeapWrapper::HeapWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<HeapWrapper>(info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    int length = info.Length();
    if (length != 2 || !info[0].IsArray())
    {
        Napi::TypeError::New(env, "Arguments Missing. (Array, String)").ThrowAsJavaScriptException();
    }

    Napi::Array value = info[0].As<Napi::Array>();
    std::string type = info[1].As<Napi::String>().ToString();
    std::vector<int> ele;
    for (int i = 0; i < value.Length(); i++)
    {

        Napi::Value val = value[i];
        ele.push_back((int)val.As<Napi::Number>());
    }
    this->_heap = new Heap(ele, type);
}

Napi::Value HeapWrapper::popWrap(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    int min = this->_heap->pop();

    return Napi::Number::New(env, min);
}