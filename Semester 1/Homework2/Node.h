#ifndef NODE_H
#define NODE_H

class LList;
class Iterator;

class Node
{
    public:
        Node(int data);

    private:
        int data;
        Node* ptr_prev;
        Node* ptr_next;
        
    friend class LList;
    friend class Iterator;
};

#endif
