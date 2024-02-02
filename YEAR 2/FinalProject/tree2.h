#ifndef TREE2_H
#define TREE2_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// __________ Node __________
template <typename T>
class Node
{
public:
    Node(T data);
    bool containingData(T data);
private:
    T val1;
    T val2;
    T val3;

    Node* chld1;
    Node* chld2;
    Node* chld3;
    Node* chld4;
};

template <typename T>
Node<T>::Node(T data)
{
    val1 = data;
    val2 = 0;
    val3 = 0;

    chld1 = chld2 = chld3 = chld4 = nullptr;
}

template <typename T>
bool Node<T>::containingData(T data)
{
    return (val1 == data || val2 == data || val3 == data);
}
// __________ Node __________

// __________ Tree __________
template <typename T>
class Tree
{
public:
    Tree();
    void insert(T data);
    Node<T>* search(T value);

private:
    Node<T>* root;

};//class Tree

template <typename T>
Tree<T>::Tree()
{
    root = nullptr;
}

template <typename T>
void Tree<T>::insert(T data)
{
    if (root == nullptr)
    {
        root = new Node<T>(data);
    }
    else
    {
        //here
    }
}//insert

template <typename T>
Node<T>* Tree<T>::search(T value)
{
    // Call a recursive function to handle search
    return searchRecursive(root, value);
}

template <typename T>
Node<T>* searchRecursive(Node<T>* currentNode, T value)
{
    if (currentNode == nullptr)
        return nullptr;

    if (currentNode->containingData(value))
        return currentNode;

    // Find the appropriate child to traverse
    if (value < currentNode->val1)
    {
        return searchRecursive(currentNode->chld1, value);
    }
        
    else if ((currentNode->val2 == nullptr && value > currentNode->val1) || (currentNode->val2 != nullptr && value < currentNode->val2))
    {
        return searchRecursive(currentNode->chld2, value);
    }
        
    else if ((currentNode->val3 == nullptr && value > currentNode->val2) || (currentNode->val3 != nullptr && value < currentNode->val3))
    {
        return searchRecursive(currentNode->chld3, value);
    }
   
    else
    {
        return searchRecursive(currentNode->chld4, value);
    }
}
// __________ Tree __________

#endif
