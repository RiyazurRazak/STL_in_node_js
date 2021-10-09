#include <napi.h>
#include "../headers/heap/wrapper.h"
#include "../headers/stack/wrapper.h"
#include "../headers/queue/wrapper.h"
#include "../headers/reversenumber.h"

Napi::Object InitAll(Napi::Env env, Napi::Object exports)
{
  HeapWrapper::Init(env, exports);
  StackWrapper::Init(env, exports);
  QueueWrapper::Init(env, exports);
  reversenumber::Init(env, exports);
  return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, InitAll)