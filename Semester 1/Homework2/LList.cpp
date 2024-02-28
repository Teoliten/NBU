#include <cassert>

using namespace std;

#include "Node.h"
#include "Iterator.h"
#include "LList.h"

LList::LList()
{
    ptr_frst = nullptr;
    ptr_last = nullptr;
}//LList

LList::~LList()
{
    while(ptr_frst)
    {
        Node* ptr_tmp = ptr_frst;
        ptr_frst = ptr_frst->ptr_next;
        delete ptr_tmp;
        ptr_tmp = nullptr;
    }
}//~LList

void LList::pushBack(int data)
{
    Node* ptr_newn = new Node(data);
    if (!ptr_frst)
    {
        ptr_frst = ptr_newn;
        ptr_last = ptr_newn;
    }
    else
    {
        ptr_newn->ptr_prev = ptr_last;
        ptr_last->ptr_next = ptr_newn;
        ptr_last = ptr_newn;
    }
}//pushBack

void LList::pushFront(int data)
{
    Node* ptr_newn = new Node(data);
    
}

Iterator LList::begin()
{    
    return Iterator(ptr_frst, this);
}//begin

Iterator LList::end()
{    
    return Iterator(nullptr, this);
}//end

void LList::insert(Iterator pos, int data)
{
    if (!pos.ptr_pos)
    {
        pushBack(data);
    }
    else
    {
        Node* ptr_newn = new Node(data);
        Node* ptr_bfr = pos.ptr_pos->ptr_prev;
        ptr_newn->ptr_prev = ptr_bfr;
        ptr_newn->ptr_next = pos.ptr_pos;
        pos.ptr_pos->ptr_prev = ptr_newn;
        (ptr_bfr ? ptr_bfr->ptr_next : ptr_frst) = ptr_newn;
    }
}//insert

Iterator LList::erase(Iterator pos)
{
    assert(pos.ptr_pos);
    Node* ptr_remv = pos.ptr_pos;
    pos.ptr_pos = pos.ptr_pos->ptr_next;

    (ptr_remv == ptr_frst ? ptr_frst : ptr_remv->ptr_prev->ptr_next) = ptr_remv->ptr_next;
    (ptr_remv == ptr_last ? ptr_last : ptr_remv->ptr_next->ptr_prev) = ptr_remv->ptr_prev;

    delete ptr_remv;
    ptr_remv = nullptr;

    return pos;    
}//erase
