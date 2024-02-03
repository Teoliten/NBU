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
    int nrValues();
    bool isLeaf();

    T val1;
    T val2;
    T val3;
    T val4; // temporary storage

    Node* chld1;
    Node* chld2;
    Node* chld3;
    Node* chld4;
    Node* chld5; //temporary pointer
};

template <typename T>
Node<T>::Node(T data)
{
    val1 = data;
    val2 = 0;
    val3 = 0;
    val4 = 0;

    chld1 = chld2 = chld3 = chld4 = chld5 = nullptr;
}

template <typename T>
bool Node<T>::containingData(T data)
{
    return (val1 == data || val2 == data || val3 == data || val4 == data);//val4?
}

template <typename T>
int Node<T>::nrValues()
{
    int result = 0;
    if(val1 != 0)
    {
        result++;
    }
    if(val2 != 0)
    {
        result++;
    }
    if(val3 != 0)
    {
        result++;
    }
    if(val4 != 0)
    {
        result++;
    }
    return result;
}

template <typename T>
bool Node<T>::isLeaf()
{
    return(chld1 == nullptr && chld2 == nullptr && chld3 == nullptr && chld4 == nullptr && chld5 == nullptr);
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
    Node<T>* find(T value);
    Node<T>* search(T value); //searching for node to put value into
    void balance(Node<T>* node);//after inserting
    void deleteVal(T value);
    
private:
    Node<T>* root;
    bool insertIntoNode(Node<T>* node, T data);
    Node<T>* getParent(Node<T>* current, Node<T>* child);
    Node<T>* findRecursive(Node<T>* currentNode, T value);
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
        bool nodeOverflow = insertIntoNode(leafNode, data);
        if(nodeOverflow)
        {
            balance(leafNode);
        }
    }
}//insert

template <typename T>
void Tree<T>::balance(Node<T>* node)
{
    // cout << "BALANCING" << endl;
    if(node == root)
    {
        //create the new nodes for splitting into
        Node<T>* newRoot = new Node<T>(node->val3);
        Node<T>* newNode = new Node<T>(node->val4);

        //set the new roots children
        newRoot->chld1 = node;
        newRoot->chld2 = newNode;

        //get pointers to newNode from node
        newNode->chld1 = node->chld4;
        newNode->chld2 = node->chld5;

        //ptrs given to newNode, set old to null
        node->chld4 = nullptr;
        node->chld5 = nullptr;

        //values given to newNode, empty now
        node->val3 = 0;
        node->val4 = 0;

        //update root
        root = newRoot;
    }
    else
    {
        Node<T>* parent = getParent(root, node);//get parent node
        
        
        //get what child we are in from parent
        bool inChld1 = false, inChld2 = false, inChld3 = false, inChld4 = false;
        if(parent->chld1 != nullptr)
        {
            inChld1 = parent->chld1->containingData(node->val3);
        }
        if(parent->chld2 != nullptr)
        {
            inChld2 = parent->chld2->containingData(node->val3);
        }
        if(parent->chld3 != nullptr)
        {
            inChld3 = parent->chld3->containingData(node->val3);
        }
        if(parent->chld4 != nullptr)
        {
            inChld4 = parent->chld4->containingData(node->val3);
        }
        
        insertIntoNode(parent, node->val3); // insert 0 0 z 0 into parent node

        Node<T>* newNode = new Node<T>(0);
        newNode->val1 = node->val4;
        node->val3 = 0;
        node->val4 = 0;

        if(inChld1)// we know val3 went into pos 1 of parent
        {
            parent->chld5 = parent->chld4;
            parent->chld4 = parent->chld3;
            parent->chld3 = parent->chld2;
            parent->chld2 = newNode;
            parent->chld1 = node;
        }
        if(inChld2)// we know val3 went into pos 2 of parent
        {
            parent->chld5 = parent->chld4;
            parent->chld4 = parent->chld3;
            parent->chld3 = newNode;
            parent->chld2 = node;
            //chld1 remains the same
        }
        if(inChld3)// we know val3 went into pos 3 of parent
        {
            parent->chld5 = parent->chld4;
            parent->chld4 = newNode;
            parent->chld3 = node;
            //chld2 remains the same
            //chld1 remains the same
        }
        if(inChld4)// we know val3 went into pos 4 of parent
        {
            parent->chld5 = newNode;
            parent->chld4 = node;
            //chld3 remains the same
            //chld2 remains the same
            //chld1 remains the same
        }

        // ASDASDASDASNode<T>* fixChildren = find(node->val3);


        //update children of the new right node
        newNode->chld1 = node->chld4;//When balacing a node thats not a leaf node, need to keep the child pointers from the old node
        newNode->chld2 = node->chld5;

        //val in parent's left child is node
        //val in parent's right child is newNode
        // node x y 0 0
        // newNode 0 0 0 k

        int valuesInParent = (parent->nrValues());
        
        if (valuesInParent == 4)// balance in parent is overflown
        {
            balance(parent);
        }
    }
}//balance

template <typename T>
bool Tree<T>::insertIntoNode(Node<T>* node, T data)
{
    // Insert data into the node and sort the values
    if (node->val1 == 0)//should never happen
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
    else if (node->val4 == 0)
    {
        node->val4 = data;
        if (node->val4 < node->val3)
        {
            swap(node->val3, node->val4);
        }
        if (node->val3 < node->val2)
        {
            swap(node->val2, node->val3);
        }
        if (node->val2 < node->val1)
        {
            swap(node->val1, node->val2);
        }
        return true;
    }
    return false;
}//insertIntoNode

template <typename T>
Node<T>* Tree<T>::find(T value)
{
    // Call a recursive function to handle find
    return findRecursive(root, value);
}//find

template <typename T>
Node<T>* Tree<T>::findRecursive(Node<T>* currentNode, T value)
{
    if (currentNode == nullptr)
        return nullptr;

    if (currentNode->containingData(value))
        return currentNode;

    // Find the appropriate child to traverse
    if (value < currentNode->val1)
    {
        return findRecursive(currentNode->chld1, value);
    }
    else if ((currentNode->val2 == 0 && value > currentNode->val1) || (currentNode->val2 != 0 && value < currentNode->val2))
    {
        return findRecursive(currentNode->chld2, value);
    }
    else if ((currentNode->val3 == 0 && value > currentNode->val2) || (currentNode->val3 != 0 && value < currentNode->val3))
    {
        return findRecursive(currentNode->chld3, value);
    }
    else
    {
        return findRecursive(currentNode->chld4, value);
    }
}//findRecursive

template <typename T>
Node<T>* Tree<T>::search(T value)
{
    // Call a recursive function to handle search
    return searchRecursive(root, value);
}//search

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
}//searchRecursive

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
}//getParent

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
        // Traverse the right subtree
        inOrderTraversal(currentNode->chld4, depth + 1);

        // Print the values of the current node with indentation based on depth
        for (int i = 0; i < depth; ++i) {
            cout << "   ";  // Adjust the number of spaces for indentation
        }

        if(depth == 0)
        {
            cout << "Root: ";
        }

        cout << "[" << currentNode->val1;
        if (currentNode->val2 != 0)
            cout << ", " << currentNode->val2;
        if (currentNode->val3 != 0)
            cout << ", " << currentNode->val3;
        if (currentNode->val4 != 0)
            cout << ", " << currentNode->val4;
        cout << "]" << endl;

        // Traverse the left and middle subtrees
        inOrderTraversal(currentNode->chld1, depth + 1);
        inOrderTraversal(currentNode->chld2, depth + 1);
        inOrderTraversal(currentNode->chld3, depth + 1);
    }
}



#endif
