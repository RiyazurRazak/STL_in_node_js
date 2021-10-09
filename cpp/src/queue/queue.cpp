#include "../../headers/queue/queue.h"

Queue::Queue(){};

void Queue::push(int value)
{
    this->_queue.push(value);
}

int Queue::pop()
{
    int value = this->_queue.front();
    this->_queue.pop();
    return value;
}