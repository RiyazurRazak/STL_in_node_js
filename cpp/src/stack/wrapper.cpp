#include "../../headers/stack/wrapper.h"

Napi::FunctionReference StackWrapper::constructor;

StackWrapper::StackWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<StackWrapper>(info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);
    this->_stack = new Stack();
}

void StackWrapper::pushWrap(const Napi::CallbackInfo &info)
{

    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);
    int value = info[0].As<Napi::Number>();
    this->_stack->push(value);
}

Napi::Value StackWrapper::popWrap(const Napi::CallbackInfo &info)
{

    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    int value = this->_stack->pop();
    return Napi::Number::New(env, value);
}

Napi::Object StackWrapper::Init(Napi::Env env, Napi::Object exports)
{

    Napi::HandleScope scope(env);

    Napi::Function func = DefineClass(env, "stack",
                                      {
                                          InstanceMethod("push", &StackWrapper::pushWrap),
                                          InstanceMethod("pop", &StackWrapper::popWrap),
                                      });

    constructor = Napi::Persistent(func);
    constructor.SuppressDestruct();

    exports.Set("stack", func);
    return exports;
}