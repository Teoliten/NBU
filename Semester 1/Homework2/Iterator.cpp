#include <cassert>

using namespace std;

#include "Node.h"
#include "LList.h"
#include "Iterator.h"

Iterator::Iterator()
{
    ptr_pos = nullptr;
    ptr_cnt = nullptr;
}//Iterator

Iterator::Iterator(Node* ptr_pos, LList* ptr_cnt)
{
    this->ptr_pos = ptr_pos;
    this->ptr_cnt = ptr_cnt;
}//Iterator

int Iterator::get() const
{
    assert(ptr_pos);
    return ptr_pos->data;
}//get

void Iterator::set(int data) const
{
    assert(ptr_pos);
    ptr_pos->data = data;
}//set

void Iterator::next()
{
    assert(ptr_pos);
	ptr_pos = ptr_pos->ptr_next;
}//next

void Iterator::prev()
{
    assert(ptr_pos != ptr_cnt->ptr_frst);
    ptr_pos = ptr_pos ? ptr_pos->ptr_prev : ptr_cnt->ptr_last;	
}//prev

bool Iterator::equals(const Iterator &iter) const
{
    return ptr_pos == iter.ptr_pos;
}//equals

bool Iterator::isNull() const
{
    return !ptr_pos;
}//isNUll
