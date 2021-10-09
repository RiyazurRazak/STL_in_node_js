#include "../../headers/stack/stack.h"

Stack::Stack(){};

void Stack::push(int value)
{
    this->_container.push(value);
}

int Stack::pop()
{
    int value = this->_container.top();
    this->_container.pop();
    return value;
}
