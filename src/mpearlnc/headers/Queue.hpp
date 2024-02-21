#ifndef QUEUE_H
#define QUEUE_H
#include "LinkedList.hpp"


template <typename T>
struct CustomQueue
{
    LinkedList<T> list;
    void enqueue(T value)
    {
        this->list.insertAtEnd(value);
        return;
    }

    void dequeue()
    {
        this->list.deleteFromBeginning();
        return;
    }

    T peek()
    {
        return this->list.getHead().data;
    }

    bool isEmpty()
    {
        return this->list.isEmpty();
    }

    int size()
    {
        return this->list.dims();
    }

    void clear()
    {
        this->list.deleteList();
    }

    int search(T value)
    {
        return this->list.search(value);
    }

    void traverse()
    {
        this->list.traverse();
    }
};

#endif