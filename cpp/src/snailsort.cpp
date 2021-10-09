#include "../headers/snailsort.h"

using namespace std;

std::vector<int> snailsort::sort(std::vector<std::vector<int>> input)
{
    if (input.size() > 1)
    {
        std::vector<int> answers;

        for (int &ele : input[0])
        {
            answers.push_back(ele);
        }

        input.erase(input.begin());

        for (int i = 0; i < input.size(); i++)
        {
            answers.push_back(input[i].back());
            input[i].pop_back();
        }

        for (int i = input[input.size() - 1].size() - 1; i >= 0; i--)
        {
            answers.push_back(input[input.size() - 1][i]);
        }

        std::reverse(input.begin(), input.end());

        input.erase(input.begin());

        for (int i = 0; i < input.size(); i++)
        {
            answers.push_back(input[i].front());
            input[i].erase(input[i].begin());
        }

        if (input.size() > 0)
        {

            std::reverse(input.begin(), input.end());

            std::vector<int> recursive = snailsort::sort(input);

            for (int &e : recursive)
            {
                answers.push_back(e);
            }
        }

        return answers;
    }
    else
    {
        return input[0];
    }
}

Napi::Value snailsort::sortWrap(const Napi::CallbackInfo &info)
{

    Napi::Env env = info.Env();
    Napi::Array input = info[0].As<Napi::Array>();
    int length = input.Length();
    std::vector<std::vector<int>> vecInput;
    for (int i = 0; i < length; i++)
    {
        Napi::Value elements = input[i];
        Napi::Array row = elements.As<Napi::Array>();
        std::vector<int> vec;
        for (int j = 0; j < row.Length(); j++)
        {
            Napi::Value val = row[j];

            vec.push_back((int)val.As<Napi::Number>());
        }
        vecInput.push_back(vec);
    }
    std::vector<int> result = snailsort::sort(vecInput);

    Napi::Array val = Napi::Array::New(env, result.size());
    for (int i = 0; i < result.size(); i++)
    {
        val[i] = result[i];
    }

    return val;
}

Napi::Object snailsort::Init(Napi::Env env, Napi::Object exports)
{

    exports.Set("snailsort", Napi::Function::New(env, snailsort::sortWrap));
    return exports;
}