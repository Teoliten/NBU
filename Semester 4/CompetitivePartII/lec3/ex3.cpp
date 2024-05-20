#include <bits/stdc++.h>
#include <list>

using namespace std;

class Node()
{
public:
  Node(int value);
  setRight(Node* ptr_node);
  setLeft(Node* ptr_node);

private:
  int data;
  Node* ptr_right;
  Node* ptr_left;
};// class Node

Node::Node(int value)
{
  data = value;
  ptr_right = nullptr;
  ptr_left = nullptr;
}

class LL()
{
public:
  LL();
  addNode(int data);

private:
  int size = 0;
  Node* ptr_root;

friend class Node;
};

LL::LL()
{
  size = 0;
}

LL::addNode(int data)
{
  newNode = new Node(int data);

  if(!size)
  {
    newNode.setRight(nullptr);
    newNode.setLeft(nullptr);
  }

}

int main()
{
  LL linkedlist;
  LL.addNode(5);

  return 0;
}