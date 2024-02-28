#include <iostream>

using namespace std;
// throw
class QueueEmpty : public runtime_error
{
public:
  QueueEmpty(const string &m) : runtime_error(m) {}
};
// throw

// ---Node---
class Node
{
public:
  Node(int data);

private:
  int data;
  Node *next;
  friend class queue;
};

Node::Node(int data)
{
  this->data = data;
  next = nullptr;
} // Node
// ---Node---

// ---queue---
class queue
{
public:
  queue();
  void enqueue(int data);
  void dequeue();
  int rear();
  int front();
  int size();
  bool isEmpty();
  void print();

private:
  Node *frontNode;
  Node *rearNode;
  int qSize;
};

queue::queue()
{
  frontNode = nullptr;
  rearNode = nullptr;
  qSize = 0;
} // queue

void queue::enqueue(int data)
{
  Node *newNode = new Node(data);
  if (isEmpty()) // first node to be added
  {
    frontNode = newNode;
    rearNode = newNode;

    frontNode->next = rearNode;
  }
  else
  {
    newNode->next = rearNode;
    rearNode = newNode;
  }
  qSize++;
} // enqueue

void queue::dequeue()
{
  if (isEmpty())
  {
    throw QueueEmpty("Err: Queue is empty!");
  }
  if (rearNode == frontNode)
  {
    delete frontNode;
    rearNode = nullptr;
    frontNode = nullptr;
    qSize--;
  }
  else
  {
    Node *tmp = rearNode;
    while (tmp->next != frontNode)
    {
      tmp = tmp->next;
    }
    tmp->next = rearNode;
    delete frontNode;
    frontNode = tmp;
    qSize--;

    if (isEmpty())
    {
      rearNode = nullptr;
      frontNode = nullptr;
    }
  }
} // dequeue

int queue::rear()
{
  if (isEmpty())
  {
    throw QueueEmpty("Err: QueueEmpty!");
  }
  return rearNode->data;
} // rear

int queue::front()
{
  if (isEmpty())
  {
    throw QueueEmpty("Err: QueueEmpty!");
  }
  return frontNode->data;
} // front

int queue::size()
{
  return qSize;
} // size

bool queue::isEmpty()
{
  return (qSize == 0);
} // isEmpty

void queue::print()
{
  if (isEmpty())
  {
    throw QueueEmpty("Print_Err: Queue empty!");
  }
  cout << "Queue: ";
  Node *current = rearNode;
  for (int i = 0; i < qSize; i++)
  {
    cout << current->data << " ";
    current = current->next;
  }
  cout << endl;
}

// ---queue---

int main()
{
  queue q;
  q.enqueue(42);
  q.enqueue(5);
  // 5 42
  // cout << "f == r: " << (q.front() == q.rear()) << endl;
  q.dequeue(); // remove 42
  // 5
  q.enqueue(11);
  // 11 5
  cout << "isEmpty: " << q.isEmpty() << endl;
  q.dequeue(); // remove 5
  // 11
  // cout << "f == r: " << (q.front() == q.rear()) << endl;

  q.dequeue();
  // empty
  cout << "isEmpty: " << q.isEmpty() << endl;
  // q.dequeue();

  q.print();

  // cout << "Front: " << q.front() << endl;
  // cout << "Rear: " << q.rear() << endl;
  return 0;
} // main