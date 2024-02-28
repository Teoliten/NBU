#ifndef QUEUE_H
#define QUEUE_H

class Node;

class Queue
{
public:
    Queue();
    ~Queue();
    void push(int data);
    void pop();
    int front() const;
    bool empty() const;

private:
    Node* ptr_head;
    Node* ptr_tail;

};//Queue


#endif