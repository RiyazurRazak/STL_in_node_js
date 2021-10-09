#include "bits/stdc++.h"

class Queue
{
    std::queue<int> _queue;

public:
    Queue();
    void push(int);
    int pop();
};