#include "napi.h"
#include "./heap.h"

class HeapWrapper : public Napi::ObjectWrap<HeapWrapper>
{
public:
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
    HeapWrapper(const Napi::CallbackInfo &info);

private:
    static Napi::FunctionReference constructor;
    Napi::Value popWrap(const Napi::CallbackInfo &info);
    Heap *_heap;
};