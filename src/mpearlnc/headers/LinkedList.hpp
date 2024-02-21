// LinkedList.h
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"
#include <iostream>
using namespace std;

template <typename T>
struct LinkedList
{
    Node<T> *head = NULL;
    Node<T> *tail = NULL;
    int size = 0;

    void insertAtEnd(T data)
    {
        struct Node<T> *newNode = (struct Node<T> *)malloc(sizeof(Node<T>));
        if (newNode != NULL)
        {
            newNode->data = data;
            newNode->next = NULL;
            if (this->head == NULL)
            {
                this->head = newNode;
                this->tail = newNode;
            }
            else
            {
                this->tail->next = newNode;
                this->tail = newNode;
            }
            this->size++;
        }
    }

    void insertAtBeginning(T data)
    {
        struct Node<T> *newNode = (struct Node<T> *)malloc(sizeof(Node<T>));
        if (newNode != NULL)
        {
            newNode->data = data;
            newNode->next = this->head;
            this->head = newNode;
            if (this->tail == NULL)
            {
                this->tail = newNode;
            }
            this->size++;
        }
        else
        {
            cout << "Memory allocation failed" << endl;
        }
    }
    void insertAfterNode(Node<T> *node, T data)
    {
        if (node == NULL)
        {
            cout << "Node cannot be NULL" << endl;
            return;
        }
        Node<T> *newNode = (struct Node<T> *)malloc(sizeof(Node<T>));
        newNode->data = data;
        newNode->next = node->next;
        node->next = newNode;
        if (this->tail == node)
        {
            this->tail = newNode;
        }
        this->size++;
    }
    void insertAtIndex(int index, T data)
    {
        if (index < 0 || index > this->size)
        {
            cout << "Invalid index" << endl;
            return;
        }
        if (index == 0)
        {
            insertAtBeginning(data);
        }
        else if (index == this->size)
        {
            insertAtEnd(data);
        }
        else
        {
            struct Node<T> *temp = this->head;
            for (int i = 0; i < index - 1; i++)
            {
                temp = temp->next;
            }
            struct Node<T> *newNode = (Node<T> *)malloc(sizeof(Node<T>));
            newNode->data = data;
            newNode->next = temp->next;
            temp->next = newNode;
            this->size++;
        }
    }

    void deleteFromBeginning()
    {
        struct Node<T> *curr_head = this->head;
        this->head = curr_head->next;
        this->size--;
        free(curr_head);
    }

    void deleteFromEnd()
    {
        struct Node<T> *curr_item = this->head;
        while (curr_item->next->next != NULL)
        {
            curr_item = curr_item->next;
        }
        struct Node<T> *temp = curr_item->next;
        curr_item->next = NULL;
        this->tail = curr_item;
        free(temp);
        this->size--;
    }

    void deleteAfterNode(Node<T> *node)
    {
        if (node->next == NULL)
        {
            return;
        }
        Node<T> *item_to_del = node->next;
        if (item_to_del.next == NULL)
        {
            node->next = NULL;
            this->tail = node;
            free(item_to_del);
            this->size--;
            return;
        }
        node->next = item_to_del.next;
        free(item_to_del);
        this->size--;
        return;
    }

    void deleteAtIndex(int index)
    {
        int loc = 0;
        if (index >= this->size)
        {
            cerr << "Requested index must be within range 0 and " << this->size << endl;
        }
        Node<T> *curr_item = this->head;
        while (loc < index)
        {
            curr_item = curr_item->next;
            loc++;
        }
        free(curr_item);
        this->size--;
        return;
    }
    Node<T> getNodeAtIndex(int index)
    {
        int loc = 0;
        if (index >= this->size)
        {
            cerr << "Requested index must be within range 0 and " << this->size << endl;
        }
        Node<T> *curr_item = this->head;
        while (loc < index)
        {
            curr_item = curr_item->next;
            loc++;
        }
        return *curr_item;
    }
    void traverse()
    {
        if(this->head==NULL){
            cout<<" empty"<<endl;
            return;
        }
        Node<T> *curr_item = this->head;
        cout << "[";
        while (curr_item->next)
        {
            if (curr_item == this->head)
            {
                cout << curr_item->data;
            }
            else
            {
                cout << ", " << curr_item->data;
            }
            curr_item = curr_item->next;
        }
        cout << "]" << endl;
        return;
    }
    void traverse_vert()
    {
        Node<T> *curr_item = this->head;
        while (curr_item->next)
        {
            cout << curr_item->data << endl;
            curr_item = curr_item->next;
        }
        return;
    }

    int search(T data)
    {
        Node<T> *curr_item = this->head;
        int loc = 0;
        while (curr_item->next != NULL)
        {
            if (curr_item->data == data)
            {
                return loc;
            }
            curr_item = curr_item->next;
            loc++;
        }
        return -1;
    }

    bool isEmpty()
    {
        if (this->size == 0)
        {

            return true;
        }

        return false;
    }

    int dims()
    {
        return this->size;
    }
    Node<T> getHead()
    {
        return *this->head;
    }

    Node<T> getTail()
    {
        return *this->tail;
    }
    void deleteList()
    {
        Node<T> *curr_item = this->head;
        while (curr_item->next != NULL)
        {
            Node<T> *temp = curr_item;
            curr_item = curr_item->next;
            free(temp);
        }
        this->head = NULL;
        this->tail = NULL;
        this->size = 0;
    }
    void reverse()
    {
        Node<T> *prev = NULL;
        Node<T> *curr = this->head;
        Node<T> *next = NULL;
        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        this->tail = this->head;
        this->head = prev;
    };
    void traverse_vert_reverse()
    {
    }
};

#endif
