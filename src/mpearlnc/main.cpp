#include <iostream>
#include "LinkedList.hpp"
#include "CustomStack.hpp"
#include "Queue.hpp"


void linkedListOperations(){
    LinkedList<int> list;
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtEnd(4);
    list.insertAtIndex(2, 5);
    list.insertAtIndex(0, 6);
    list.traverse();
    list.insertAfterNode(list.head, 7);
    list.traverse();
    Node<int> node = list.getNodeAtIndex(2);
    list.insertAfterNode(&node, 8);
    list.traverse();
    cout << "Size of list: " << list.dims() << endl;
    cout<<"Searching for 5:" <<list.search(5)<<endl;
    list.traverse();
    printf("Is list empty: %d\n", list.isEmpty()==1?true:false);
}

void stackOperations(){
    CustomStack<int> stack;
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.traverse();
    stack.pop();
    stack.traverse();
    cout << "Top of stack: " << stack.peek() << endl;
    cout << "Size of stack: " << stack.size() << endl;
    printf("Is stack empty: %d\n", stack.isEmpty()==1?true:false);
    stack.clear();
    stack.traverse();
}

void queueOperations(){
    CustomQueue<int> queue;
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);
    queue.enqueue(6);
    queue.traverse();
    queue.dequeue();
    queue.traverse();
    cout << "Front of queue: " << queue.peek() << endl;
    cout << "Size of queue: " << queue.size() << endl;
    printf("Is queue empty: %d\n", queue.isEmpty()==1?true:false);
    queue.clear();
    queue.traverse();
}

int main()
{
   cout << "Linked List Operations" << endl;
   cout << "----------------------" << endl;
    linkedListOperations();
    cout<<"______________________"<<endl;
    cout << "Stack Operations" << endl;
    cout << "----------------------" << endl;
    stackOperations();
    cout<<"______________________"<<endl;

    cout << "Queue Operations" << endl;
    cout << "----------------------" << endl;
    queueOperations();

    return 0;
    
}
