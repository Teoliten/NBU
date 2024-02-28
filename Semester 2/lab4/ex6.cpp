#include <iostream>

using namespace std;

class LListFull : public runtime_error
{
    public:
        LListFull(const string &m) : runtime_error(m) {}
};

class LListEmpty : public runtime_error
{
    public:
        LListEmpty(const string &m) : runtime_error(m) {}
};

template <typename E>
class LList;//LList

template <typename E>
class Node
{
    public:
        Node(const E &elmt);

    private:
        E data;
        Node<E>* ptr_next;
        Node<E>* ptr_prev;

    friend class LList<E>;
};//Node


template <typename E>
class LList
{
    public:
        LList();
        ~LList();
        void pushFront(const E &e);
        void popFront();
        void pushBack(const E &e);
        void popBack();
        const E &front() const;
        const E &back() const;

    private:
        Node<E>* ptr_frst;
        Node<E>* ptr_last;
};


template <typename E>
void LList<E>::pushFront(const E &e)
{
    Node<E>* ptr_newn = new Node<E>(e);
    if (!ptr_frst)
    {
        ptr_frst = ptr_newn;
        ptr_last = ptr_newn;
    }
    else
    {
        ptr_newn->ptr_next =
        ptr_frst;
        ptr_frst->ptr_prev =
        ptr_newn;
        ptr_frst = ptr_newn;
    }
}

template <typename E>
void LList<E>::popFront()
{
    if (!ptr_frst)
    {
        throw LListEmpty(...);
    }
    Node<E>* ptr_tmp = ptr_frst;
    ptr_frst = ptr_frst->ptr_next;
    ptr_frst->ptr_prev = nullptr;
    delete ptr_tmp;
    ptr_tmp = nullptr;
}


int main()
{

    return 0;
}//main