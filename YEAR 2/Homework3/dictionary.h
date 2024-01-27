#include <iostream>
#include <vector>

using namespace std;

// _____________ NODE _____________
template <typename tkey, typename tval>
class Node 
{
public:
    tkey key;
    vector<tval> values;
    Node* left;
    Node* right;

    Node(const tkey& key, const tval& value, Node* left = nullptr, Node* right = nullptr);
};//class Node

template<typename tkey, typename tval>
Node<tkey, tval>::Node(const tkey& key, const tval& value, Node* left, Node* right) : key(key), values(1, value), left(left), right(right) 
{
}//Node parameter constructor
// _____________ NODE _____________



// _____________ ITERATOR _____________
template <typename tkey, typename tval>
class Iterator 
{
private:
    using Node = Node<tkey, tval>;
    
    Node* current;
    vector<Node*> nodes;
    
public:
    Iterator(Node* root);
    Iterator& operator++();                                     //overloaded increment operator ++
    pair<const tkey&, const vector<tval>&> operator*() const;   //overloaded dereference operator *
    bool operator==(const Iterator& other) const;               //overloaded equality operator ==
    bool operator!=(const Iterator& other) const;               //overloaded inequality operator !=
};//class Iterator

template <typename tkey, typename tval>
Iterator<tkey, tval>::Iterator(Node* root)
{
    this->current = root;
    // Move to the leftmost node
    while (current) {
        nodes.push_back(current);
        current = current->left;
    }
    // Set current to the leftmost node
    if (!nodes.empty()) {
        current = nodes.back();
        nodes.pop_back();
    }
}//Iterator


template <typename tkey, typename tval>
Iterator<tkey, tval>& Iterator<tkey, tval>::operator++() 
{
    // Move to the next node in in-order traversal
    if (current->right) 
    {
        current = current->right;
        while (current) {
            nodes.push_back(current);
            current = current->left;
        }
    } 
    else if (!nodes.empty()) 
    {
        current = nodes.back();
        nodes.pop_back();
    } 
    else 
    {
        current = nullptr; // End of traversal
    }
    return *this;
}//overloaded increment operator ++


template <typename tkey, typename tval>
pair<const tkey&, const vector<tval>&> Iterator<tkey, tval>::operator*() const 
{
    return make_pair(current->key, current->values);
}//overloaded dereference operator *


template <typename tkey, typename tval>
bool Iterator<tkey, tval>::operator==(const Iterator& other) const 
{
    return (current == other.current && nodes == other.nodes);
}//overloaded equality operator ==


template <typename tkey, typename tval>
bool Iterator<tkey, tval>::operator!=(const Iterator& other) const 
{
    return !(*this == other);
}//overloaded inequality operator !=
// _____________ ITERATOR _____________



// _____________ DICTIONARY _____________
template <typename tkey, typename tval>
class Dictionary 
{
private:
    Node<tkey, tval>* root;

    Node<tkey, tval>* insert(Node<tkey, tval>* node, const tkey& key, const tval& value);
    Node<tkey, tval>* find(Node<tkey, tval>* node, const tkey& key) const;
    pair<Node<tkey, tval>*, Node<tkey, tval>*> findAll(Node<tkey, tval>* node, const tkey& key);
    Node<tkey, tval>* erase(Node<tkey, tval>* node, const tkey& key);
    Node<tkey, tval>* erase(Node<tkey, tval>* node, Node<tkey, tval>* target);

    Node<tkey, tval>* minValueNode(Node<tkey, tval>* node) const;
    int size(Node<tkey, tval>* node) const;

public:
    Dictionary() : root(nullptr) {}

    void insert(const tkey& key, const tval& value);
    Iterator<tkey, tval> find(const tkey& key);
    pair<Iterator<tkey, tval>, Iterator<tkey, tval>> findAll(const tkey& key);
    void erase(const tkey& key);
    void erase(const Iterator<tkey, tval>& position);

    bool empty() const;
    int size() const;

    Iterator<tkey, tval> begin() const;
    Iterator<tkey, tval> end() const;
};//class Dictionary

template <typename tkey, typename tval>
void Dictionary<tkey, tval>::insert(const tkey& key, const tval& value) 
{
    root = insert(root, key, value);
}//insert

template <typename tkey, typename tval>
Iterator<tkey, tval> Dictionary<tkey, tval>::find(const tkey& key) 
{
    Node<tkey, tval>* result = find(root, key);
    return Iterator<tkey, tval>(result);
}//find

template <typename tkey, typename tval>
pair<Iterator<tkey, tval>, Iterator<tkey, tval>> Dictionary<tkey, tval>::findAll(const tkey& key) 
{
    auto result = findAll(root, key);
    return {Iterator<tkey, tval>(result.first), Iterator<tkey, tval>(result.second)};
}//findAll

template <typename tkey, typename tval>
void Dictionary<tkey, tval>::erase(const tkey& key) 
{
    root = erase(root, key);
}//erase

template <typename tkey, typename tval>
void Dictionary<tkey, tval>::erase(const Iterator<tkey, tval>& position) 
{
    root = erase(root, position.current);
}//erase

template <typename tkey, typename tval>
bool Dictionary<tkey, tval>::empty() const 
{
    return root == nullptr;
}//empty

template <typename tkey, typename tval>
int Dictionary<tkey, tval>::size() const 
{
    return size(root);

}//size

template <typename tkey, typename tval>
Iterator<tkey, tval> Dictionary<tkey, tval>::begin() const 
{
    return Iterator<tkey, tval>(minValueNode(root));
}//begin

template <typename tkey, typename tval>
Iterator<tkey, tval> Dictionary<tkey, tval>::end() const 
{
    return Iterator<tkey, tval>(nullptr);
}//end

template <typename tkey, typename tval>
Node<tkey, tval>* Dictionary<tkey, tval>::insert(Node<tkey, tval>* node, const tkey& key, const tval& value) 
{
    if (node == nullptr) {
        return new Node<tkey, tval>(key, value);
    } 
    else if (key < node->key) 
    {
        node->left = insert(node->left, key, value);
    } 
    else if (key > node->key) 
    {
        node->right = insert(node->right, key, value);
    } 
    else 
    {
        node->values.push_back(value);
    }
    return node;
}//insert

template <typename tkey, typename tval>
Node<tkey, tval>* Dictionary<tkey, tval>::find(Node<tkey, tval>* node, const tkey& key) const 
{
    if (node == nullptr || node->key == key) 
    {
        return node;
    } 
    else if (key < node->key) 
    {
        return find(node->left, key);
    } 
    else 
    {
        return find(node->right, key);
    }
}//find

template <typename tkey, typename tval>
pair<Node<tkey, tval>*, Node<tkey, tval>*> Dictionary<tkey, tval>::findAll(Node<tkey, tval>* node, const tkey& key) 
{
    Node<tkey, tval>* first = nullptr;
    Node<tkey, tval>* last = nullptr;

    while (node) 
    {
        if (key < node->key) 
        {
            node = node->left;
        } 
        else if (key > node->key) 
        {
            node = node->right;
        } 
        else 
        {
            first = last = node;
            while (last->right && last->right->key == key) 
            {
                last = last->right;
            }
            break;
        }
    }

    return {first, last};
}//findAll

template <typename tkey, typename tval>
Node<tkey, tval>* Dictionary<tkey, tval>::erase(Node<tkey, tval>* node, const tkey& key) 
{
    if (node == nullptr) 
    {
        return nullptr;
    } 
    else if (key < node->key) 
    {
        node->left = erase(node->left, key);
    } 
    else if (key > node->key) 
    {
        node->right = erase(node->right, key);
    } 
    else 
    {
        if (node->left == nullptr) 
        {
            Node<tkey, tval>* temp = node->right;
            delete node;
            return temp;
        } 
        else if (node->right == nullptr) 
        {
            Node<tkey, tval>* temp = node->left;
            delete node;
            return temp;
        } 
        else 
        {
            Node<tkey, tval>* temp = minValueNode(node->right);
            node->key = temp->key;
            node->values = temp->values;
            node->right = erase(node->right, temp->key);
        }
    }
    return node;
}//erase by key

template <typename tkey, typename tval>
Node<tkey, tval>* Dictionary<tkey, tval>::erase(Node<tkey, tval>* node, Node<tkey, tval>* target) 
{
    return erase(node, target->key);
}//erase by iterator

template <typename tkey, typename tval>
Node<tkey, tval>* Dictionary<tkey, tval>::minValueNode(Node<tkey, tval>* node) const 
{
    Node<tkey, tval>* current = node;
    while (current && current->left) 
    {
        current = current->left;
    }
    return current;
}//minValueNode

template <typename tkey, typename tval>
int Dictionary<tkey, tval>::size(Node<tkey, tval>* node) const 
{
    if (node == nullptr) 
    {
        return 0;
    } 
    else 
    {
        return size(node->left) + 1 + size(node->right);
    }
}//size
// _____________ DICTIONARY _____________