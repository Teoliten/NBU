#ifndef TREE_H
#define TREE_H

#include <list>
#include <stdexcept>

using namespace std;



// ------------------TreeExcept------------------
class TreeExcept : public runtime_error{
    public:
        TreeExcept(const string &msg);
};//TreeExcept
// ------------------TreeExcept------------------



// // ------------------Function Declarations------------------
// template <typename TKey>
// class GTree;

// template <typename TKey>
// class GTree<TKey>::Position;
// // ------------------Function Declarations------------------



// ------------------GTree------------------
template <typename TKey>
class GTree
{
    public:
        class Node;//tree composed of nodes
        class Position;//like iterator

        GTree();
        ~GTree();

        void setRoot(const TKey &key);
        Position addChld(const Position &pos, const TKey &key);

        int size() const;
        bool empty() const;

    private:
        Node* ptr_root;
        int numb;
        void deleteTree(Node* ptr_node);
};//GTree

template <typename TKey>
GTree<TKey>::GTree(){
    ptr_root = nullptr;
    numb = 0;
}//GTree

template <typename TKey>
GTree<TKey>::~GTree()
{
    deleteTree(ptr_root);
}//~GTree

template <typename TKey>
typename GTree<TKey>::Position GTree<TKey>::addChld(const Position &pos, const TKey &key)
{
    if (!pos.ptr_node)
    {
        throw TreeExcept("Invalid position.");
    }

    Node *ptr_newn = new Node(key);
    ptr_newn->ptr_prnt = pos.ptr_node;
    pos.ptr_node->chld.push_back(ptr_newn);
    numb++;

    return Position(ptr_newn);
}

template <typename TKey>
void GTree<TKey>::setRoot(const TKey &key)
{
    if(ptr_root)
    {
        throw TreeExcept("Root already exists.");
    }
    ptr_root = new Node(key);
    numb = 1;
}

template <typename TKey>
int GTree<TKey>::size() const
{
    return numb;
}//size

template <typename TKey>
bool GTree<TKey>::empty() const
{
    return (size() == 0);
}//empty

template <typename TKey>
void GTree<TKey>::deleteTree(Node* ptr_node)
{
    if (ptr_node)
    {
        for (typename list< Node* >::iterator iter = ptr_node->chld.begin(); iter != ptr_node->chld.end(); ++iter)
        {
            deleteTree(*iter);
        }
        delete ptr_node;
        ptr_node = nullptr;
        numb--;
    }
}//deleteTree
// ------------------GTree------------------



// ------------------Position------------------
template <typename TKey>
class GTree<TKey>::Position{
    public:
        Position();
        Position(GTree<TKey>::Node* ptr_node);
        Position(const Position &pos);

        Position &operator =(const Position &pos);
        TKey &operator *();

        bool isRoot() const;
        bool isExternal() const;
        typename getRoot() const;

        Position parent() const;
        list<GTree<TKey>::Node*> &chldList() const;

    private:
        GTree<TKey>::Node* ptr_node;

    friend class GTree<TKey>;
};//Position

template <typename TKey>
GTree<TKey>::Position::Position()
{
    ptr_node = nullptr;
}//Position

template <typename TKey>
GTree<TKey>::Position::Position(GTree<TKey>::Node* ptr_node)
{
    this->ptr_node = ptr_node;
}//Position

template <typename TKey>
GTree<TKey>::Position::Position(const Position &pos)
{
    ptr_node = pos.ptr_node;
}//Position

template <typename TKey>
typename GTree<TKey>::Position& GTree<TKey>::Position::operator=(const Position &pos)
{
    ptr_node = pos.ptr_node;
    return *this;
}//operator =

//dereference operator
template <typename TKey>
TKey &GTree<TKey>::Position::operator *()
{
    if(!ptr_node)
    {
        throw TreeExcept("Error: dereference of null position.");
    }
    else
    {
        return ptr_node->key;
    }
}//operator *

template <typename TKey>
bool GTree<TKey>::Position::isRoot() const
{
    if(!ptr_node)
    {
        throw TreeExcept("Empty Tree.");
    }
    return (!ptr_node->ptr_prnt);
}//isRoot

template <typename TKey>
bool GTree<TKey>::Position::isExternal() const
{
    if(!ptr_node)
    {
        throw TreeExcept("Empty Tree.");
    }
    return (ptr_node->chld.size() == 0);
}//isExternal

template <typename TKey>
typename GTree<TKey>::Position GTree<TKey>::Position::getRoot() const
{
    return Position(ptr_root);
}//getRoot

template <typename TKey>
typename GTree<TKey>::Position GTree<TKey>::Position::parent() const
{
    if(ptr_node && ptr_node->ptr_prnt)
    {
        return Position(ptr_node->ptr_prnt);
    }
    throw runtime_error("No parent for the current node.");
}//parent

template <typename TKey>
list<typename GTree<TKey>::Node*> &GTree<TKey>::Position::chldList() const
{
    if(ptr_node)
    {
        return ptr_node->chld;
    }
    throw runtime_error("Empty node.");
}//chldList
// ------------------Position------------------



// ------------------Node------------------
template <typename TKey>
class GTree<TKey>::Node
{
    public:
        Node(const TKey &key);

    private:
        TKey key;
        Node* ptr_prnt;
        list <Node*> chld;

    friend class GTree<TKey>;
};//Node

template <typename TKey>
GTree<TKey>::Node::Node(const TKey &key){
    this->key = key;
    ptr_prnt = nullptr;
}//Node
// ------------------Node------------------



#endif