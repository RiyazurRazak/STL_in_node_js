#include "../../headers/heap/heap.h"

Heap::Heap(std::vector<int> values, std::string type)
{
    this->_type = type;
    if (type == "min")
    {
        for (int &ele : values)
        {
            this->_min.push(ele);
        }
    }
    else
    {
        for (int &ele : values)
        {
            this->_max.push(ele);
        }
    }
}

int Heap::pop()
{
    if (this->_type == "min")
    {
        int val = Heap::_min.top();
        this->_min.pop();
        return val;
    }
    else
    {
        int val = Heap::_max.top();
        this->_max.pop();
        return val;
    }
}