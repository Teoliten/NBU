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
    val2 = val3 = nullptr;

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
    Node<T>* searchParent(Node<T>* currentNode, T value);
private:
    Node<T>* root;

    // Add other necessary private functions for tree operations
};

template <typename T>
Tree<T>::Tree() : root(nullptr) {}

template <typename T>
void Tree<T>::insert(T data)
{
    if (root == nullptr)
    {
        root = new Node<T>(data);
    }
    else
    {
        Node<T>* node = search(data);
        Node<T>* parent = searchParent(root, data);

        if (node->keys.size() < 3)
        {
            node->insertKey(data);
        }
        else
        {
            T promote = node->keys[1];
            Node<T>* nodeL = new Node<T>(node->keys[0]);
            Node<T>* nodeR = new Node<T>(node->keys[2]);
            delete node;

            if (data < promote)
            {
                insertRecursive(nodeL, data);
            }
            else
            {
                insertRecursive(nodeR, data);
            }

            insert(parent, promote);

            while (parent->keys.size() == 3)
            {
                T parentPromote = parent->keys[1];
                Node<T>* parentL = new Node<T>(parent->keys[0]);
                Node<T>* parentR = new Node<T>(parent->keys[2]);
                delete parent;

                parentL->children[0] = nodeL;
                parentL->children[1] = nodeR;
                parentR->children[0] = parent->children[2];
                parentR->children[1] = parent->children[3];

                insert(searchParent(root, parentPromote), parentPromote);

                if (parent == root && root->keys.size() == 3)
                {
                    Node<T>* newRoot = new Node<T>(parentPromote);
                    newRoot->children[0] = parentL;
                    newRoot->children[1] = parentR;
                    root = newRoot;
                }
            }
        }
    }
}

// Helper function to find the parent of a node containing a specific value
template <typename T>
Node<T>* Tree<T>::searchParent(Node<T>* currentNode, T value)
{
    if (currentNode == nullptr)
    {
        return nullptr;
    }

    if (currentNode->containingData(value))
    {
        return nullptr;
    }

    if (currentNode->children[0]->containingData(value) ||
        currentNode->children[1]->containingData(value) ||
        (currentNode->children[2] && currentNode->children[2]->containingData(value)) ||
        (currentNode->children[3] && currentNode->children[3]->containingData(value)))
    {
        return currentNode;
    }

    if (value < currentNode->keys[0])
    {
        return searchParent(currentNode->children[0], value);
    }
    else if (currentNode->keys.size() == 1 || (currentNode->keys.size() == 2 && value < currentNode->keys[1]))
    {
        return searchParent(currentNode->children[1], value);
    }
    else if (currentNode->keys.size() == 2 || (currentNode->keys.size() == 3 && value < currentNode->keys[2]))
    {
        return searchParent(currentNode->children[2], value);
    }
    else
    {
        return searchParent(currentNode->children[3], value);
    }
}

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
