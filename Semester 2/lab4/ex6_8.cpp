#include <iostream>

using namespace std;
// throw
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
// throw

template <typename E>
class LList;

//-----------NODE-----------
template <typename E>
class Node
{
public:
  Node(const E &elmt);

private:
  E data;
  Node<E> *prev;
  Node<E> *next;

  friend class LList<E>;
}; // Node

template <typename E>
Node<E>::Node(const E &elmt) // default constructor
{
  this->data = elmt;
  prev = nullptr;
  next = nullptr;
} // Node
//-----------NODE-----------

//-----------LList-----------
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
  Node<E> *frst;
  Node<E> *last;
};

// constructor
template <typename E>
LList<E>::LList()
{
  frst = nullptr;
  last = nullptr;
} // LList

// destructor
template <typename E>
LList<E>::~LList()
{
  while (frst)
  {
    Node<E> *tmp = frst;
    frst = frst->next;
    delete tmp;
  }
} //~LList

template <typename E>
void LList<E>::pushFront(const E &e)
{
  Node<E> *newNode = new Node<E>(e);
  if (!frst)
  {
    frst = newNode;
    last = newNode;
  }
  else
  {
    newNode->next = frst;
    frst->prev = newNode;
    frst = newNode;
  }
} // pushFront

template <typename E>
void LList<E>::popFront()
{
  if (!frst)
  {
    throw LListEmpty("Err: list empty!");
  }
  else
  {
    Node<E> *tmp = frst;
    if (frst->next)
    {
      frst = frst->next;
      frst->prev = nullptr;
    }
    else
    {
      frst = nullptr;
      last = nullptr;
    }
    delete tmp;
    tmp = nullptr;
  }
} // popFront

template <typename E>
void LList<E>::pushBack(const E &e)
{
  Node<E> *newNode = new Node<E>(e);

  if (!frst)
  {
    frst = newNode;
    last = newNode;
  }
  else
  {
    last->next = newNode;
    newNode->prev = last;
    last = newNode;
  }
} // pushBack

template <typename E>
void LList<E>::popBack()
{
  if (!last)
  {
    cout << "Err: empty list!" << endl;
  }
  else
  {
    if (last->prev)
    {
      Node<E> *tmp = last;
      last = last->prev;
      last->next = nullptr;
      delete tmp;
    }
    else
    {
      delete last;
      frst = nullptr;
      last = nullptr;
    }
  }
} // popBack

template <typename E>
const E &LList<E>::front() const
{
  if (frst)
    return frst->data;
  else
    throw LListEmpty("Error: empty list!");
} // front

template <typename E>
const E &LList<E>::back() const
{
  if (last)
    return last->data;
  else
    throw LListEmpty("Error: empty list!");
} // back

//-----------LList-----------

template <typename E>
class Deque : public LList<E>
{
public:
  void pushFront(const E &e);
  void pushBack(const E &e);
}; // Deque

template <typename E>
void Deque<E>::pushFront(const E &e)
{
  LList<E>::pushFront(e);
} // pushFront

template <typename E>
void Deque<E>::pushBack(const E &e)
{
  LList<E>::pushBack(e);
} // pushBack

int main()
{
  LList<int> ll;
  ll.pushFront(11);
  ll.pushFront(2);
  ll.pushFront(55);
  ll.pushFront(5);

  ll.popBack();
  ll.popFront();

  ll.pushBack(42);

  try
  {
    cout << "Front: " << ll.front() << endl;
    cout << "Back: " << ll.back() << endl;
  }
  catch (const LListEmpty &ex)
  {
    cout << ex.what() << endl;
  }
  // 5 55 2 11
  return 0;
}