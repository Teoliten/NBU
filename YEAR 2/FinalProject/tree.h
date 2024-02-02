#ifndef TREE_H
#define TREE_H

using namespace std;

#include <vector>
// ________ Node ________
template <typename T>
class Node 
{
public:
    Node(T data);
    void dataAppend(T data);
    T data;
    vector<T> list_data; // 1, 2 or 3
    int nrChildren;           // 2, 3 or 4
    Node<T>* parent;
    vector<Node<T>*> children;
    
};//Class Node

template <typename T>
Node<T>::Node(T data) : data(data), nrChildren(2), parent(nullptr) 
{    
}//Parameter constructor

template <typename T>
void Node<T>::dataAppend(T data) {
    list_data.push_back(data);
}//dataAppend
// ________ Node ________

// ________ Tree ________
template <typename T>
class Tree {
public:
    Tree();

    void insert(T value);
    void deleteVal(int value);
    Node<T>* find(T val);

    void printTree();

private:
    Node<T>* root;
    int size;

    void insert(Node<T>* node, T value);
    void split(Node<T>* parent, Node<T>* new_node);
    void printTree(Node<T>* node, int depth);
};

template <typename T>
Tree<T>::Tree()
{
    root = nullptr;
    size = 0;
}//Tree


template <typename T>
void Tree<T>::insert(T value)
{
    if (root == nullptr) // Empty tree
    {
        Node<T>* new_node = new Node<T>(value);
        root = new_node;
        size++;
    }
    else
    {
        // Call a recursive helper function to handle the insertion
        insert(root, value);
    }
}

template <typename T>
void Tree<T>::insert(Node<T>* node, T value)
{
    if (node->children.empty()) // Check if the current node is a leaf
    {
        if (node->list_data.size() < 3)
        {
            node->dataAppend(value);
            size++;
        }
        else
        {
            Node<T>* new_node = new Node<T>(value);
            split(node, new_node);
        }
    }
    else
    {
        // Find the appropriate child to insert into
        int i = 0;
        while (i < node->list_data.size() && value > node->list_data[i])
        {
            i++;
        }

        // Recursively insert into the appropriate child
        insert(node->children[i], value);
    }
}

template <typename T>
void Tree<T>::split(Node<T>* parent, Node<T>* new_node)
{
    // Split a full node into two and insert the new node

    // Assuming here that the parent node is not full
    parent->dataAppend(new_node->list_data[0]);

    // Split the new_node's children between parent and new_node
    parent->children.push_back(new_node->children[0]);
    parent->children.push_back(new_node->children[1]);

    // Remove the split children from new_node
    new_node->children.erase(new_node->children.begin(), new_node->children.begin() + 2);

    // Update list_data of new_node
    new_node->list_data.erase(new_node->list_data.begin(), new_node->list_data.begin() + 1);

    // Insert new_node as a child of parent
    int i = 0;
    while (i < parent->list_data.size() && new_node->list_data[0] > parent->list_data[i])
    {
        i++;
    }
    parent->children.insert(parent->children.begin() + i, new_node);
}



template <typename T>
void Tree<T>::deleteVal(int value)
{
    // Implementation of delete method
}

template <typename T>
Node<T>* find(T val)
{

}


template <typename T>
void Tree<T>::printTree()
{
    printTree(root, 0);
}

template <typename T>
void Tree<T>::printTree(Node<T>* node, int depth)
{
    // Print the data in the current node
    for (int i = 0; i < depth; i++)
        cout << "  ";
    cout << node->data << endl;

    // Recursively print the children of the current node
    for (Node<T>* child : node->children)
        printTree(child, depth + 1);
}

// ________ Tree ________
#endif