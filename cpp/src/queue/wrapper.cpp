#include "../../headers/queue/wrapper.h"

Napi::FunctionReference QueueWrapper::constructor;

QueueWrapper::QueueWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<QueueWrapper>(info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);
    this->_queue = new Queue();
}

void QueueWrapper::pushWrap(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    int value = info[0].As<Napi::Number>();
    this->_queue->push(value);
}

Napi::Value QueueWrapper::popWrap(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);
    int value = this->_queue->pop();
    return Napi::Number::New(env, value);
}

Napi::Object QueueWrapper::Init(Napi::Env env, Napi::Object exports)
{

    Napi::HandleScope scope(env);
    Napi::Function func = DefineClass(env, "queue", {
                                                        InstanceMethod("push", &QueueWrapper::pushWrap),
                                                        InstanceMethod("pop", &QueueWrapper::popWrap),
                                                    });

    constructor = Napi::Persistent(func);
    constructor.SuppressDestruct();

    exports.Set("queue", func);
    return exports;
}