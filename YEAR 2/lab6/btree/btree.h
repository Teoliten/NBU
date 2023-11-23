#ifndef BTREE_H
#define BTREE_H

#include <string>
#include <stdexcept>

using namespace std;

//-----------------TreeExcept-----------------
class TreeExcept : public runtime_error
{
public:
  // parameter constructor
  TreeExcept(const string &msg);
};

TreeExcept::TreeExcept(const string &msg) : runtime_error(msg)
{

} // TreeExcept
//-----------------TreeExcept-----------------

//-----------------BTree-----------------
template <typename TKey> // Binary tree class
class BTree
{
public:
  class Node;                                          // tree build out of nodes
  class Position;                                      // position in tree
  BTree();                                             // default constructor
  ~BTree();                                            // destructor
  void setRoot(const TKey &key);                       // set root of tree
  Position getRoot() const;                            // gives position of root
  void setLeft(const Position &pos, const TKey &key);  // set left child node
  void setRight(const Position &pos, const TKey &key); // set right child node

private:
  void deleteTree(Node *ptr_node); // recursivly delete tree

  Node *ptr_root; // root of tree
  int numb;       // number of nodes

}; // BTree

template <typename TKey>
BTree<TKey>::BTree() : ptr_root(nullptr),
                       numb(0)
{
} // BTree

template <typename TKey>
BTree<TKey>::~BTree()
{
  deleteTree(ptr_root);
} // ~BTree

template <typename TKey>
void BTree<TKey>::deleteTree(Node *ptr_node)
{
  if (ptr_node)
  {
    deleteTree(ptr_node->ptr_left);
    deleteTree(ptr_node->ptr_right);
    delete ptr_node;
    ptr_node = nullptr;
  }
} // deleteTree

template <typename TKey>
void BTree<TKey>::setRoot(const TKey &key)
{
  if (ptr_root)
  {
    throw TreeExcept("Root already exists.");
  }
  ptr_root = new Node(key);
  numb = 1;
} // setRoot

template <typename TKey>
typename BTree<TKey>::Position
BTree<TKey>::getRoot() const
{
  return Position(ptr_root);
} // getRoot

template <typename TKey>
void BTree<TKey>::setLeft(const Position &pos, const TKey &key)
{
  if (pos.ptr_node->ptr_left)
  {
    throw TreeExcept("Left already exists.");
  }
  pos.ptr_node->ptr_left = new Node(key);
  pos.ptr_node->ptr_left->ptr_prnt = pos.ptr_node;
  numb++;
} // setLeft

template <typename TKey>
void BTree<TKey>::setRight(const Position &pos, const TKey &key)
{
  if (pos.ptr_node->ptr_right)
  {
    throw TreeExcept("Right already exists.");
  }
  pos.ptr_node->ptr_right = new Node(key);
  pos.ptr_node->ptr_right->ptr_prnt = pos.ptr_node;
  numb++;
} // setRight
//-----------------BTree-----------------

//-----------------Node-----------------
template <typename TKey>
class BTree<TKey>::Node
{
public:
  Node(const TKey &key_p); // parameter constructor

private:
  TKey key;        // node key
  Node *ptr_prnt;  // pointer to partent
  Node *ptr_left;  // left child
  Node *ptr_right; // right child

  friend class BTree<TKey>;
}; // Class Node

//--------------------HOMEWORK--------------------move constructor----------read book----------

template <typename TKey>
BTree<TKey>::Node::Node(const TKey &key_p) : key(key_p),
                                             ptr_prnt(nullptr),
                                             ptr_left(nullptr),
                                             ptr_right(nullptr)
{
} // Node
//-----------------Node-----------------

//-----------------Position-----------------
template <typename TKey>
class BTree<TKey>::Position
{
public:
  typedef BTree<TKey>::Node BTNode;         // type BTree with name BTNode
  Position();                               // default constructor
  Position(BTNode *ptr_node_p);             // parameter constructor
  Position(const Position &pos);            // copy constructor
  Position &operator=(const Position &pos); // operator overloading =
  TKey &operator*();                        // dereference operator
  Position parent() const;                  // return parent node
  Position left() const;                    // return left node
  Position right() const;                   // return right node
  bool isRoot() const;                      // check if it is root
  bool isExternal() const;                  // chech if it is external

private:
  BTNode *ptr_node; // pointer to current node

  friend class BTree<TKey>;
}; // Position

template <typename TKey>
BTree<TKey>::Position::Position() : ptr_node(nullptr)
{
} // Position

template <typename TKey>
BTree<TKey>::Position::Position(BTNode *ptr_node_p) : ptr_node(ptr_node_p)
{
} // Position

template <typename TKey>
BTree<TKey>::Position::Position(const Position &pos) : ptr_node(pos.ptr_node)
{
} // Position

template <typename TKey>
typename BTree<TKey>::Position &
BTree<TKey>::Position::operator=(const Position &pos)
{
  ptr_node = pos.ptr_node;
  return *this;
} // operator =

template <typename TKey>
TKey &BTree<TKey>::Position::operator*()
{
  if (!ptr_node)
  {
    throw TreeExcept("Dereference null.");
  }
  return ptr_node->key;
} // dereference operator

template <typename TKey>
typename BTree<TKey>::Position::parent() const
{
  if (!ptr_node)
  {
    throw TreeExcept("Dereference null.");
  }
  return Position(ptr_node->ptr_prnt);
} // node parent

template <typename TKey>
typename BTree<TKey>::Position::left() const
{
  if (!ptr_node)
  {
    throw TreeExcept("Dereference null.");
  }
  return Position(ptr_node->ptr_left);
} // node left

template <typename TKey>
typename BTree<TKey>::Position::right() const
{
  if (!ptr_node)
  {
    throw TreeExcept("Dereference null.");
  }
  return Position(ptr_node->ptr_right);
} // node right

template <typename TKey>
bool BTree<TKey>::Position::isRoot const
{
  if (!ptr_node)
  {
    throw TreeExcept("Dereference null.");
  }
  return (!ptr_node->ptr_prnt);
} // isRoot

template <typename TKey>
bool BTree<TKey>::Position::isExternal const
{
  if (!ptr_node)
  {
    throw TreeExcept("Dereference null.");
  }
  return !(ptr_node->ptr_left || ptr_node->ptr_right);
} // isExternal
//-----------------Position-----------------

#endif