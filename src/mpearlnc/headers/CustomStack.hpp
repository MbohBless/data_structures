// CustomStack.h
#ifndef CUSTOMSTACK_H
#define CUSTOMSTACK_H
#include "LinkedList.hpp"

template <typename T>
struct CustomStack
{
    LinkedList<T> list;
    void push(T value)
    {
        this->list.insertAtEnd(value);
        return;
    }

    void pop()
    {
        this->list.deleteFromEnd();
        return;
    }

    T peek()
    {
        return this->list.getTail().data;
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