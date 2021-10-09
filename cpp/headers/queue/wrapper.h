#include "napi.h"
#include "./queue.h"

class QueueWrapper : public Napi::ObjectWrap<QueueWrapper>
{
    static Napi::FunctionReference constructor;
    void pushWrap(const Napi::CallbackInfo &info);
    Napi::Value popWrap(const Napi::CallbackInfo &info);
    Queue *_queue;

public:
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
    QueueWrapper(const Napi::CallbackInfo &info);
};