#ifndef LLIST_H
#define LLIST_H

class Node;
class Iterator;

class LList
{
    public:
        LList();
        ~LList();
        void pushBack(int data);
        void pushFront(int data);
        Iterator begin();
        Iterator end();
        void insert(Iterator pos, int data);
        Iterator erase(Iterator pos);

    private:
        Node* ptr_frst;
        Node* ptr_last;

    friend class Iterator;
};

#endif
