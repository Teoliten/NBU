#include <cassert>

using namespace std;

#include "Node.h"
#include "Queue.h"

Queue::Queue()
{
    ptr_head = nullptr;
    ptr_tail = nullptr;
}//Queue

Queue::~Queue()
{
    while(ptr_head)
    {
        Node* ptr_tmp = ptr_head;
        ptr_head = ptr_head->ptr_next;
        delete ptr_tmp;
        ptr_tmp = nullptr;
    }
}//~Queue

void Queue::push(int data)
{
    Node* ptr_newn = new Node(data);
    if(ptr_tail) // if exists
    {
        ptr_tail->ptr_next = ptr_newn;
    }
    else
    {
        ptr_head = ptr_newn;
    }
    //(ptr_tail ? ptr_tail->ptr_next : ptr_head) = ptr_newn;
    ptr_tail = ptr_newn;
}//push

void Queue::pop()
{
    assert(ptr_head);
    Node* ptr_tmp = ptr_head;
    if(ptr_tmp == ptr_tail)
    {
        ptr_head = nullptr;
        ptr_tail = nullptr;
    }
    else
    {
        ptr_head = ptr_head->ptr_next;
    }
    delete ptr_tmp;
    ptr_tmp = nullptr;
}//pop

int Queue::front() const
{
    assert(ptr_head);
    return ptr_head->data;
}//front

bool Queue::empty() const
{
    return (ptr_tail == nullptr);
}//empty



