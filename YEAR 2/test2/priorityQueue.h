#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

using namespace std;

#include <iostream>
#include <string>
#include <sstream>

//______________NODE______________
template <typename T>
class Node
{
public:
  Node(T data);

  T data;
  Node *ptr_next;
};

template <typename T>
Node<T>::Node(T data)
{
  this->data = data;
  ptr_next = nullptr;
}
//______________NODE______________

//______________COMPARE LEXI______________
class compareLexi
{
public:
  bool operator()(const string &frst, const string &scnd);
}; // class compareLexi

bool compareLexi::operator()(const string &frst, const string &scnd)
{
  return frst < scnd;
} // operator ()
//______________COMPARE LEXI______________

//______________COMPARE INT______________
class compareInt
{
public:
  bool operator()(const string &frst, const string &scnd);

private:
  int toInt(const string &data);
}; // class compareInt

bool compareInt::operator()(const string &frst, const string &scnd)
{
  return toInt(frst) < toInt(scnd);
} // operator ()

int compareInt::toInt(const string &data)
{
  istringstream iss(data);

  int result;
  iss >> result;

  if (iss.fail())
  {
    throw runtime_error("Can't convert to integer.");
  }

  return result;
} // toInt
//______________COMPAREINT______________

//______________PRIORITY QUEUE______________
template <typename T, typename Compare = less<T>>
class PriorityQueue
{
public:
  PriorityQueue(Compare comp = Compare());
  ~PriorityQueue();

  void push(T data);
  void pop();

  T top();
  bool empty();

  void printQueue();

private:
  Node<T> *ptr_frst;
  Compare comp;
}; // class Priority Queue

template <typename T, typename Compare>
PriorityQueue<T, Compare>::PriorityQueue(Compare comp) : comp(comp)
{
  ptr_frst = nullptr;
} // constructor

template <typename T, typename Compare>
PriorityQueue<T, Compare>::~PriorityQueue()
{
  while (ptr_frst)
  {
    Node<T> *tmp = ptr_frst;
    ptr_frst = ptr_frst->ptr_next;
    delete tmp;
  }
} // destructor

template <typename T, typename Compare>
void PriorityQueue<T, Compare>::push(T data)
{
  Node<T> *new_node = new Node<T>(data);
  if (!ptr_frst || comp(data, ptr_frst->data))
  {
    new_node->ptr_next = ptr_frst;
    ptr_frst = new_node;
  }
  else
  {
    Node<T> *current = ptr_frst;
    while (current->ptr_next && comp(current->ptr_next->data, data))
    {
      current = current->ptr_next;
    }
    new_node->ptr_next = current->ptr_next;
    current->ptr_next = new_node;
  }
} // push

template <typename T, typename Compare>
void PriorityQueue<T, Compare>::pop()
{
  if (ptr_frst)
  {
    Node<T> *tmp = ptr_frst;
    ptr_frst = ptr_frst->ptr_next;
    delete tmp;
  }
} // pop

template <typename T, typename Compare>
T PriorityQueue<T, Compare>::top()
{
  if (ptr_frst)
  {
    return ptr_frst->data;
  }
  throw runtime_error("Queue is empty");
} // top

template <typename T, typename Compare>
bool PriorityQueue<T, Compare>::empty()
{
  return ptr_frst == nullptr;
} // empty

template <typename T, typename Compare>
void PriorityQueue<T, Compare>::printQueue()
{
  Node<T> *current = ptr_frst;
  while (current)
  {
    cout << current->data << " ";
    current = current->ptr_next;
  }
  cout << endl;
} // printQueue
//______________PRIORITY QUEUE______________

#endif
