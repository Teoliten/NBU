#include <iostream>

using namespace std;

#include "clist.h"

// default constructor
Clist::Clist()
{
  ptr_crsr = nullptr;
} // Clist

// destructor
Clist::~Clist()
{
  while (!isEmpty())
  {
    remove();
  }

  if (ptr_crsr)
  {
    delete[] ptr_crsr;
    ptr_crsr = nullptr;
  }
} //~Clist

void Clist::add(int data)
{
  Node *ptr_new = new Node;
  ptr_new->data = data;

  if (!ptr_crsr) // empty list
  {
    ptr_new->ptr_next = ptr_new;
    ptr_crsr = ptr_new;
  }
  else // list already contains nodes
  {
    ptr_new->ptr_next =
        ptr_crsr->ptr_next = ptr_new;
  }
} // add

int Clist::front() const
{
  return ptr_crsr->ptr_next->data;
} // front

int Clist::back() const
{
  return ptr_crsr->data;
} // back

void Clist::advance()
{
  ptr_crsr = ptr_crsr->ptr_next;
}

// Check if list is empty
bool Clist::isEmpty() const
{
  return (!ptr_crsr);
} // isEmpty

// Remove after cursor
void Clist::remove()
{
  Node *ptr_tmp = ptr_crsr->ptr_next;
  if (ptr_tmp == ptr_crsr)
  {
    ptr_crsr = nullptr;
  }
  else
  {
    ptr_crsr->ptr_next = ptr_tmp->ptr_next;
  }
  delete ptr_tmp;
  ptr_tmp = nullptr;
} // remove