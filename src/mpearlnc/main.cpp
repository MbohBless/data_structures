#include <iostream>
#include "LinkedList.hpp"
#include "CustomStack.hpp"


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

int main()
{
   cout << "Linked List Operations" << endl;
   cout << "----------------------" << endl;
    linkedListOperations();
    cout<<"______________________"<<endl;
    cout << "Stack Operations" << endl;
    cout << "----------------------" << endl;
    stackOperations();

    return 0;
    
}
