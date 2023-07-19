#ifndef NODE_H
#define NODE_H

//class Queue;
class Stack;

class Node
{
    public:
        Node(int data);

    private:
        int data;
        Node* ptr_next;

    //friend class Queue;
    friend class Stack;
};

#endif
