#ifndef STACK_H
#define STACK_H

class Node;

class Stack
{
    public:
        Stack();
        ~Stack();
        void push(int data);
        void pop();
        int top() const;
        bool empty() const;
        void operator <<(int data);

    private:
        Node* ptr_head;
};

#endif
