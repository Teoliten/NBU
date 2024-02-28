#include <cassert>

using namespace std;

#include "Node.h"
#include "Stack.h"

Stack::Stack()
{
    ptr_head = nullptr;
}//Stack

Stack::~Stack()
{
    while (ptr_head)
    {
        Node* ptr_tmp = ptr_head;
        ptr_head = ptr_head->ptr_next;
        delete ptr_tmp;
        ptr_tmp = nullptr;
    }
}//~Stack

void Stack::push(int data)
{
    Node* ptr_newn = new Node(data);
    ptr_newn->ptr_next = ptr_head;
    ptr_head = ptr_newn;
}//push

void Stack::pop()
{
    assert(ptr_head);
    Node* ptr_tmp = ptr_head;
    ptr_head = ptr_head->ptr_next;
    delete ptr_tmp;
    ptr_tmp = nullptr;
}//pop

int Stack::top() const
{
    assert(ptr_head);

    return ptr_head->data;
}//front

bool Stack::empty() const
{
    return (ptr_head == nullptr);
}//empty

void Stack::operator <<(int data)
{
    push(data);
}//operator <<
