#include "napi.h"
#include "./stack.h"

class StackWrapper : public Napi::ObjectWrap<StackWrapper>
{
    static Napi::FunctionReference constructor;
    void pushWrap(const Napi::CallbackInfo &info);
    Napi::Value popWrap(const Napi::CallbackInfo &info);
    Stack *_stack;

public:
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
    StackWrapper(const Napi::CallbackInfo &info);
};