#include "napi.h"
#include "bits/stdc++.h"

namespace snailsort
{

    std::vector<int> sort(std::vector<std::vector<int>>);
    Napi::Object Init(Napi::Env env, Napi::Object exports);
    Napi::Value sortWrap(const Napi::CallbackInfo &info);
}