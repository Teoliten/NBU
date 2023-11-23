#ifndef BTREE_H
#define BTREE_H

#include <iostream>
#include <iomanip>
#include <stdexcept>

using namespace std;

//! Tree exceptions class 
/*!
    Implements exception for the tree class and nested tree classes.  
 */
class TreeExcept : public runtime_error
{
    public:

        //! Parameter constructor 
        /*!
            Construct an exception with an input message.
            \param msg      exception message 
         */
        TreeExcept(const string &msg);
};

// Parameter constructor
TreeExcept::TreeExcept(const string &msg) 
    : runtime_error(msg)
{
}//TreeExcept

//! Binary tree class 
/*!
    Binary tree class that implements a tree with nodes whose number of children can be at most two.
    \tparam TKey    type of the keys inserted in the nodes    
 */
template <typename TKey>
class BTree
{
    public:

        //! Node of the general tree 
        /*!
            Node of a general tree data structure. 
         */
        class Node;

        //! Position in the general tree 
        /*!
            Position used to visit the nodes of the general tree. 
         */
        class Position;

        //! Default constructor 
        /*!
            Construct an empty tree. 
         */
        BTree();

        //! Destructor 
        /*!
            Free memory allocated for the tree by calling the recursive member function deleteTree(). 
         */
        ~BTree();

        //! Set root of the tree 
        /*!
            Create root node and set data key in it.
            \param key              data key to be located in the root node 
         */
        void setRoot(const TKey &key);

        //! Get root of the tree 
        /*!
            Return root of the tree contained in a position object.
            \return                 position of the root of the tree 
         */ 
        Position getRoot() const;

        //! Set left child of a node 
        /*!
            Create left child node and set data key.
            \param pos              position of the parent node
            \param key              data key to be located in the root node 
         */
        void setLeft(const Position& pos, const TKey &key);

        //! Set right child of a node 
        /*!
            Create right child node and set data key.
            \param pos              position of the parent node
            \param key              data key to be located in the root node 
         */
        void setRight(const Position& pos, const TKey &key);

        //! Size of the tree 
        /*!
            Return the size of there as number of contained nodes.
            \return                 the number of nodes in the tree 
         */
        int size() const;

        //! Check if the tree is empty 
        /*!
            Return the number of nodes in the tree.
            \return                 true if the tree is empty, false otherwise 
         */
        bool empty() const;

        //! Print the tree 
        /*!
            Print the nodes of the tree by calling the recursive member function printTree().
         */
        void print() const;

    private:

        static const int SPC;           /*!< increment space in printing */

        Node* ptr_root;                 /*!< pointer to the root node */
        int numb;                       /*!< number of nodes in the tree */

        //! Recursively delete a sub-tree 
        /*!
            A recursive member function that deletes a sub-tree with the given root.
            Performs depth-first search of the tree with post-order traversal.
            \parent ptr_node        pointer to the root node of the sub-tree
         */
        void deleteTree(Node* ptr_node);

        //! Recursively print a sub-tree 
        /*!
            A recursive member function that prints a sub-tree with the given root.
            Performs in-order traversal of the tree.
            Recursively printsright sub-tree, then prints the current root, then recursively prints
            the left sub-tree.
            \parent ptr_node        pointer to the root node of the sub-tree
         */
        void printTree(const Node* ptr_node, int space) const;
};

//! Node of the binary tree 
/*!
    Node of a binary tree data structure.
    \tparam TKey    type of the keys inserted in the nodes    
 */
template <typename TKey>
class BTree<TKey>::Node
{
    public:

        //! Parameter constructor 
        /*!
            Construct a node and set the key data field.
            \param key      reference to the data key value 
         */
        Node(const TKey &key);

    private:

        TKey key;                       /*!< data key stored in the node */
        Node* ptr_prnt;                 /*!< pointer to the parent node */
        Node* ptr_left;                 /*!< pointer to the left child */
        Node* ptr_rght;                 /*!< pointer to the right child */

    friend class BTree<TKey>;
};

// class Node implementation

// parameter constructor
template <typename TKey>
BTree<TKey>::Node::Node(const TKey &key)
{
    this->key = key;
    ptr_prnt = nullptr;
    ptr_left = nullptr;
    ptr_rght = nullptr;
}//Node

//! Position in the general tree 
/*!
    Position used to visit the nodes of the general tree.
    \tparam TKey        type of the keys inserted in the nodes    
 */
template <typename TKey>
class BTree<TKey>::Position
{
    public:

        //! Default constructor 
        /*!
            Construct an empty position. 
         */
        Position();

        //! Parameter constructor 
        /*!
            Construct a position with a given pointer to a node.
            \param ptr_node         pointer to the input node
         */
        Position(BTree<TKey>::Node* ptr_node);

        //! Copy constructor 
        /*!
            Construct a position that is a copy of the position parameter.
            \param pos              reference to the position parameter
         */
        Position(const Position &pos);

        //! Overloaded assignment operator 
        /*!
            Copy the contents of the right hand-side operand into the left. 
            \param pos              reference to the position parameter
            \return                 reference to the implicit argument
         */
        Position &operator =(const Position &pos);

        //! Overloaded dereference operator 
        /*!
            Return the data key value of the pointed node. 
            \return                 key value
         */
        TKey &operator *();

        //! Return parent node 
        /*!
            Return position that points to the parent node. 
            \return                 position to the parent node
         */
        Position parent() const;

        //! Return left child node 
        /*!
            Return position that points to the left child node. 
            \return                 position to the parent node
         */
        Position left() const;

        //! Return right child node 
        /*!
            Return position that points to the right child node. 
            \return                 position to the parent node
         */
        Position right() const;

        //! Check if points to the root node
        /*!
            Check if the position points to the root node. 
            \return                 true if points to the root, false otherwise
         */
        bool isRoot() const;

        //! Check if points to an external node
        /*!
            Check if the position points to an external (leaf) node. 
            \return                 true if points to an eternal node, false otherwise
         */
        bool isExternal() const;

    private:

        BTree<TKey>::Node* ptr_node;    /*!< pointer to the node pointed by position */

    friend class BTree<TKey>;
};

// class Position implementation

// default constructor
template <typename TKey>
BTree<TKey>::Position::Position()
{
    ptr_node = nullptr;
}//Position

// parameter constructor
template <typename TKey>
BTree<TKey>::Position::Position(BTree<TKey>::Node* ptr_node)
{
    this->ptr_node = ptr_node;
}//Position

// copy constructor
template <typename TKey>
BTree<TKey>::Position::Position(const Position &pos)
{
    ptr_node = pos.ptr_node;
}//Position

// overload assignment operator
template <typename TKey>
typename BTree<TKey>::Position &BTree<TKey>::Position::operator =(const Position &pos)
{
    ptr_node = pos.ptr_node;

    return *this;
}//operator =

// overload dereference operator
template <typename TKey>
TKey &BTree<TKey>::Position::operator *()
{
    if (!ptr_node)
    {
        throw TreeExcept("BTree<TKey>::Position::operator *(): dereference null position.");
    }

    return ptr_node->key;
}//operator *

// return position to the parent node
template <typename TKey>
typename BTree<TKey>::Position BTree<TKey>::Position::parent() const
{
    if (!ptr_node)
    {
        throw TreeExcept("BTree<TKey>::Position::parent(): access null position.");
    } 

    return Position(ptr_node->ptr_prnt);
}//parent

// return position to the left child node
template <typename TKey>
typename BTree<TKey>::Position BTree<TKey>::Position::left() const
{
    if (!ptr_node)
    {
        throw TreeExcept("BTree<TKey>::Position::left(): access null position.");
    } 

    return Position(ptr_node->ptr_left);
}//left

// return position to the right child node
template <typename TKey>
typename BTree<TKey>::Position BTree<TKey>::Position::right() const
{
    if (!ptr_node)
    {
        throw TreeExcept("BTree<TKey>::Position::right(): access null position.");
    } 

    return Position(ptr_node->ptr_rght);
}//right

// check if points to the root node
template <typename TKey>
bool BTree<TKey>::Position::isRoot() const
{
    if (!ptr_node)
    {
        throw TreeExcept("BTree<TKey>::Position::isRoot(): access null position.");
    } 

    return (!ptr_node->ptr_prnt);
}//isRoot

// check if points to the external node
template <typename TKey>
bool BTree<TKey>::Position::isExternal() const
{
    if (!ptr_node)
    {
        throw TreeExcept("BTree<TKey>::Position::isExternal(): access null position.");
    } 

    return !(ptr_node->ptr_left || ptr_node->ptr_rght);
}//isRoot

// class BTree implementation

// increment space in printing
template <typename TKey>
const int BTree<TKey>::SPC = 3;

// delete recursively a sub-tree
template <typename TKey>
void BTree<TKey>::deleteTree(Node* ptr_node)
{
    if (ptr_node)
    {
        deleteTree(ptr_node->ptr_left);
        deleteTree(ptr_node->ptr_rght);
        delete ptr_node;
        ptr_node = nullptr;
        numb--;
    }
}//deleteTree

// recursively print a sub-tree
template <typename TKey>
void BTree<TKey>::printTree(const Node* ptr_node, int space) const
{
    if (ptr_node)
    {
        printTree(ptr_node->ptr_rght, space += SPC);
        cout << setw(space) << ptr_node->key << endl;
        printTree(ptr_node->ptr_left, space);
    }
}//printTree

// default constructor
template <typename TKey>
BTree<TKey>::BTree()
{
    ptr_root = nullptr;
    numb = 0;
}//BTree

// destructor
template <typename TKey>
BTree<TKey>::~BTree()
{
    deleteTree(ptr_root);
}//~BTree

// set the root node
template <typename TKey>
void BTree<TKey>::setRoot(const TKey &key)
{
    if (ptr_root)
    {
        throw TreeExcept("BTree<TKey>::setRoot(): tree already has a root.");
    } 

    ptr_root = new Node(key);
    numb = 1;
}//setRoot

// get position to the root node
template <typename TKey>
typename BTree<TKey>::Position BTree<TKey>::getRoot() const
{
    return Position(ptr_root);
}//getRoot

// set left child of a node 
template <typename TKey>
void BTree<TKey>::setLeft(const Position& pos, const TKey &key)
{
    if (pos.ptr_node->ptr_left)
    {
        throw TreeExcept("BTree<TKey>setLeft(): left child alredy exists.");
    }

    pos.ptr_node->ptr_left = new Node(key);
    pos.ptr_node->ptr_left->ptr_prnt = pos.ptr_node;
    numb++;
}//setLeft

// set right child of a node 
template <typename TKey>
void BTree<TKey>::setRight(const Position& pos, const TKey &key)
{
    if (pos.ptr_node->ptr_rght)
    {
        throw TreeExcept("BTree<TKey>setRight(): right child alredy exists.");
    }

    pos.ptr_node->ptr_rght = new Node(key);
    pos.ptr_node->ptr_rght->ptr_prnt = pos.ptr_node;
    numb++;
}//setLeft

// size of the tree
template <typename TKey>
int BTree<TKey>::size() const
{
    return numb;
}//size

// check if the tree is empty
template <typename TKey>
bool BTree<TKey>::empty() const
{
    return (numb == 0);
}//empty

// print the tree
template <typename TKey>
void BTree<TKey>::print() const
{
    printTree(ptr_root, 0);
}//print

#endif
