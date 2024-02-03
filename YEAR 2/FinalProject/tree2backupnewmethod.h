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
    bool isFull();

    T val1;
    T val2;
    T val3;

    Node* chld1;
    Node* chld2;
    Node* chld3;
    Node* chld4;

private:
    
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
bool Node<T>::isFull()
{
    return(val1 != 0 && val2 != 0 && val3 != 0);
}//isFull

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
    void print();
    Node<T>* search(T value);
    

private:
    Node<T>* root;

    void insertRecursive(Node<T>* currentNode, T data);
    void insertIntoNode(Node<T>* node, T data);
    void splitNode(Node<T>* node);
    Node<T>* getParent(Node<T>* current, Node<T>* child);
    Node<T>* searchRecursive(Node<T>* currentNode, T value);
    
    void inOrderTraversal(Node<T>* currentNode, int depth);
};

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
        Node<T>* leafNode = search(data);
        cout << leafNode->val1 << endl;
        cout << leafNode->val2 << endl;
        cout << leafNode->val3 << endl;
        cout << "isFull: " << leafNode->isFull() << endl;
        if(!(leafNode->isFull))//node is not full, put data into node
        {
            insertIntoNode(leafNode, data);
        }
        else//node is full
        {

        }
        // // Call a recursive function to handle insertion
        insertRecursive(root, data);
        
    }
}//insert

template <typename T>
void Tree<T>::insertRecursive(Node<T>* currentNode, T data)
{
    // If the current node is a 3-node, split it
    if (currentNode->val2 != 0 && currentNode->val3 != 0)
    {
        splitNode(currentNode);
        currentNode = root;
    }

    // If the current node is a leaf, insert the data
    if (currentNode->chld1 == nullptr && currentNode->chld2 == nullptr && currentNode->chld3 == nullptr && currentNode->chld4 == nullptr)
    {
        insertIntoNode(currentNode, data);
    }
    else
    {
        // Determine the appropriate child to traverse
        if (data < currentNode->val1)
        {
            insertRecursive(currentNode->chld1, data);
        }
        else if ((currentNode->val2 == 0 && data > currentNode->val1) || (currentNode->val2 != 0 && data < currentNode->val2))
        {
            insertRecursive(currentNode->chld2, data);
        }
        else if ((currentNode->val3 == 0 && data > currentNode->val2) || (currentNode->val3 != 0 && data < currentNode->val3))
        {
            insertRecursive(currentNode->chld3, data);
        }
        else
        {
            insertRecursive(currentNode->chld4, data);
        }
    }
}

template <typename T>
void Tree<T>::insertIntoNode(Node<T>* node, T data)
{
    // Insert data into the node and sort the values
    if (node->val1 == 0)
    {
        node->val1 = data;
    }
    else if (node->val2 == 0)
    {
        node->val2 = data;
        if (node->val2 < node->val1)
        {
            swap(node->val1, node->val2);
        }
    }
    else if (node->val3 == 0)
    {
        node->val3 = data;
        if (node->val3 < node->val2)
        {
            swap(node->val2, node->val3);
        }
        if (node->val2 < node->val1)
        {
            swap(node->val1, node->val2);
        }
    }
    else
    {
        // Node is full, split it and insert into the appropriate split node
        splitNode(node);

        // After splitting, find the correct child to insert the data
        if (data < node->val1)
        {
            insertIntoNode(node->chld1, data);
        }
        else if (data > node->val1 && (node->val2 == 0 || data < node->val2))
        {
            insertIntoNode(node->chld2, data);
        }
        else if (node->val2 != 0 && data > node->val2 && (node->val3 == 0 || data < node->val3))
        {
            insertIntoNode(node->chld3, data);
        }
        else if (node->val3 != 0 && data > node->val3)
        {
            insertIntoNode(node->chld4, data);
        }
    }
}


template <typename T>
void Tree<T>::splitNode(Node<T>* node)
{
    // Create a new node and redistribute values
    Node<T>* newNode = new Node<T>(0);

    newNode->val1 = node->val3;
    node->val3 = 0;  // Reset val3 for the original node

    if (node->chld3 != nullptr)
    {
        newNode->chld1 = node->chld3;
        node->chld3 = nullptr;
        newNode->chld1->chld4 = nullptr;
    }

    // If the current node is not the root, propagate the middle value to the parent
    if (node != root)
    {
        insertIntoNode(getParent(root, node), node->val2);
        node->val2 = 0;  // Reset val2 for the original node
    }

    // Connect the new node to the parent
    if (node == root)
    {
        
        Node<T>* newChild = new Node<T>(0);
        newChild->val1 = root->val1;
        root->val1 = root->val2;
        root->val2 = 0;
        root->chld1 = newChild;
        root->chld2 = newNode;
    }
    else
    {
        Node<T>* parent = getParent(root, node);
        if (parent->val2 == 0)
        {
            parent->val2 = node->val2;
            parent->chld2 = newNode;
        }
        else
        {
            parent->val3 = node->val2;
            parent->chld3 = newNode;
        }

        // Reset val2 for the original node
        node->val2 = 0;
    }
}

template <typename T>
Node<T>* Tree<T>::search(T value)
{
    // Call a recursive function to handle search
    return searchRecursive(root, value);
}

template <typename T>
Node<T>* Tree<T>::searchRecursive(Node<T>* currentNode, T value)
{
    if (currentNode == nullptr)
        return nullptr;

    // If the current node is a leaf or contains the data, return it
    if (currentNode->chld1 == nullptr && currentNode->chld2 == nullptr && currentNode->chld3 == nullptr && currentNode->chld4 == nullptr)
    {
        return currentNode;
    }

    if (currentNode->containingData(value))
        return currentNode;

    // Find the appropriate child to traverse
    if (value < currentNode->val1)
    {
        return searchRecursive(currentNode->chld1, value);
    }
    else if ((currentNode->val2 == 0 && value > currentNode->val1) || (currentNode->val2 != 0 && value < currentNode->val2))
    {
        return searchRecursive(currentNode->chld2, value);
    }
    else if ((currentNode->val3 == 0 && value > currentNode->val2) || (currentNode->val3 != 0 && value < currentNode->val3))
    {
        return searchRecursive(currentNode->chld3, value);
    }
    else
    {
        return searchRecursive(currentNode->chld4, value);
    }
}


template <typename T>
Node<T>* Tree<T>::getParent(Node<T>* current, Node<T>* child)
{
    // Find the parent of a node in the tree
    if (current->chld1 == child || current->chld2 == child || current->chld3 == child || current->chld4 == child)
    {
        return current;
    }
    else
    {
        if (child->val1 < current->val1)
        {
            return getParent(current->chld1, child);
        }
        else if ((current->val2 == 0 && child->val1 > current->val1) || (current->val2 != 0 && child->val1 < current->val2))
        {
            return getParent(current->chld2, child);
        }
        else if ((current->val3 == 0 && child->val1 > current->val2) || (current->val3 != 0 && child->val1 < current->val3))
        {
            return getParent(current->chld3, child);
        }
        else
        {
            return getParent(current->chld4, child);
        }
    }
}

template <typename T>
void Tree<T>::print()
{
    inOrderTraversal(root, 0);  // Start with depth 0
    cout << endl;
}

template <typename T>
void Tree<T>::inOrderTraversal(Node<T>* currentNode, int depth)
{
    if (currentNode != nullptr)
    {
        // Traverse the left subtree
        inOrderTraversal(currentNode->chld1, depth + 1);

        // Print the values of the current node with depth
        for (int i = 0; i < depth+1; ++i) {
            cout << "0";
        }

        cout << "[" << currentNode->val1;
        if (currentNode->val2 != 0)
            cout << ", " << currentNode->val2;
        if (currentNode->val3 != 0)
            cout << ", " << currentNode->val3;
        cout << "]" << endl;

        // Traverse the middle and right subtrees
        inOrderTraversal(currentNode->chld2, depth + 1);
        inOrderTraversal(currentNode->chld3, depth + 1);
        inOrderTraversal(currentNode->chld4, depth + 1);
    }
}


#endif
