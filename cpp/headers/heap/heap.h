#include "bits/stdc++.h"

class Heap
{
    std::priority_queue<int, std::vector<int>, std::greater<int>> _min;
    std::priority_queue<int, std::vector<int>, std::less<int>> _max;
    std::string _type = "min";

public:
    Heap(std::vector<int>, std::string);
    int pop();
};