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
    cout << "Node constructed" << endl;
    list_data.push_back(data);
}// Parameter constructor


template <typename T>
void Node<T>::dataAppend(T data) {
    cout << "dataAppend" << endl;
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
    cout << "treeConstructor" << endl;
    root = nullptr;
    size = 0;
}//Tree


template <typename T>
void Tree<T>::insert(T value)
{
    cout << "insert" << endl;
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
    cout << "insertHelper" << endl;

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
    // Create a new parent node
    Node<T>* new_parent = new Node<T>(parent->list_data[1]);
    cout << "Splitting node with data: ";
    for (const T& data : parent->list_data)
        cout << data << " ";
    cout << endl;

    // Update the new parent's children
    new_parent->children.push_back(parent);
    new_parent->children.push_back(new_node);

    // Remove the split children from the parent
    parent->children.erase(parent->children.begin(), parent->children.begin() + 2);

    // Update list_data of the parent
    parent->list_data.resize(1);

    // Update the parent of the split nodes
    parent->parent = new_parent;
    new_node->parent = new_parent;

    cout << "Creating new parent with data: " << new_node->list_data[0] << endl;

    // Print information about the children of the new parent
    cout << "Children of new parent: ";
    for (Node<T>* child : new_parent->children)
    {
        if (child != nullptr)
            cout << "[" << child->list_data[0] << "] ";
    }
    cout << endl;

    // If the parent is the root, update the root
    if (parent == root)
    {
        root = new_parent;
        cout << "Updating root" << endl;
    }
    else
    {
        // Insert the new parent into the grandparent
        split(parent->parent, new_parent);
    }
}



template <typename T>
void Tree<T>::deleteVal(int value)
{
    cout << "delete val: " << value << endl;
    // Implementation of delete method
}

template <typename T>
Node<T>* find(T val)
{
cout << "find: " << val << endl;
}


template <typename T>
void Tree<T>::printTree()
{
    cout << "print" << endl;
    printTree(root, 0);
}

template <typename T>
void Tree<T>::printTree(Node<T>* node, int depth)
{
    // Print the data in the current node
    for (int i = 0; i < depth; i++)
        cout << "  ";

    cout << "[";
    for (size_t i = 0; i < node->list_data.size(); i++)
    {
        cout << node->list_data[i];
        if (i < node->list_data.size() - 1)
            cout << ", ";
    }
    cout << "]" << endl;

    // Recursively print the children of the current node
    for (Node<T>* child : node->children)
        printTree(child, depth + 1);
}

// ________ Tree ________
#endif