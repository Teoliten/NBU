#ifndef ITERATOR_H
#define ITERATOR_H

class Node;
class LList;

class Iterator
{
    public:
        Iterator();
        Iterator(Node* ptr_pos, LList* ptr_cnt);
        int get() const;
        void set(int data) const;
        void prev();
        void next();
        bool equals(const Iterator &iter) const;
        bool isNull() const;

    private:
        Node* ptr_pos;
        LList* ptr_cnt;
    
    friend class LList;
};

#endif
