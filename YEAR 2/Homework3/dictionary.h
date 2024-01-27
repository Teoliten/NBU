#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ----------------- NODE -----------------
template <typename K, typename V>
class Node {
public:
    K key;
    vector<V> values;
    Node* left;
    Node* right;

    Node(K key, vector<V> values, Node* left = nullptr, Node* right = nullptr);
};

template <typename K, typename V>
Node<K, V>::Node(K key, vector<V> values, Node* left, Node* right)
{
    this->key = key;
    this->values = values;
    this->left = left;
    this->right = right;
}//Node
// ----------------- NODE -----------------

// ----------------- SORTED_DICTIONARY -----------------
template <typename K, typename V>
class SortedDictionary {
    Node<K, V>* root;

public:
    SortedDictionary() : root(nullptr) {}

    // Insert a key-value pair into the tree
    void insert(const K& key, const V& value) {
        root = insert(root, key, value);
    }

    // Find a key in the tree
    Node<K, V>* find(const K& key) {
        return find(root, key);
    }

    // Erase a key from the tree
    void erase(const K& key) {
        root = erase(root, key);
    }

    // Check if the tree is empty
    bool empty() {
        return root == nullptr;
    }

    // Get the size of the tree
    int size() {
        return size(root);
    }

private:
    Node<K, V>* insert(Node<K, V>* node, const K& key, const V& value) {
        if (node == nullptr) {
            node = new Node<K, V>{key, {value}, nullptr, nullptr};
        } else if (key < node->key) {
            node->left = insert(node->left, key, value);
        } else if (key > node->key) {
            node->right = insert(node->right, key, value);
        } else {
            node->values.push_back(value);
        }
        return node;
    }

    Node<K, V>* find(Node<K, V>* node, const K& key) {
        if (node == nullptr || node->key == key) {
            return node;
        } else if (key < node->key) {
            return find(node->left, key);
        } else {
            return find(node->right, key);
        }
    }

    Node<K, V>* erase(Node<K, V>* node, const K& key) {
        if (node == nullptr) {
            return nullptr;
        } else if (key < node->key) {
            node->left = erase(node->left, key);
        } else if (key > node->key) {
            node->right = erase(node->right, key);
        } else {
            if (node->left == nullptr) {
                Node<K, V>* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node<K, V>* temp = node->left;
                delete node;
                return temp;
            } else {
                Node<K, V>* temp = minValueNode(node->right);
                node->key = temp->key;
                node->values = temp->values;
                node->right = erase(node->right, temp->key);
            }
        }
        return node;
    }

    Node<K, V>* minValueNode(Node<K, V>* node) {
        Node<K, V>* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    int size(Node<K, V>* node) {
        if (node == nullptr) {
            return 0;
        } else {
            return size(node->left) + 1 + size(node->right);
        }
    }
};

// SortedDictionary member functions
template <typename K, typename V>
SortedDictionary<K, V>::SortedDictionary() : root(nullptr) {}

template <typename K, typename V>
void SortedDictionary<K, V>::insert(const K& key, const V& value) {
    root = insert(root, key, value);
}

template <typename K, typename V>
Node<K, V>* SortedDictionary<K, V>::find(const K& key) {
    return find(root, key);
}

template <typename K, typename V>
void SortedDictionary<K, V>::erase(const K& key) {
    root = erase(root, key);
}

template <typename K, typename V>
bool SortedDictionary<K, V>::empty() {
    return root == nullptr;
}

template <typename K, typename V>
int SortedDictionary<K, V>::size() {
    return size(root);
}

template <typename K, typename V>
Node<K, V>* SortedDictionary<K, V>::insert(Node<K, V>* node, const K& key, const V& value) {
    if (node == nullptr) {
        return new Node<K, V>{key, {value}, nullptr, nullptr};
    } else if (key < node->key) {
        node->left = insert(node->left, key, value);
    } else if (key > node->key) {
        node->right = insert(node->right, key, value);
    } else {
        node->values.push_back(value);
    }
    return node;
}

template <typename K, typename V>
Node<K, V>* SortedDictionary<K, V>::find(Node<K, V>* node, const K& key) {
    if (node == nullptr || node->key == key) {
        return node;
    } else if (key < node->key) {
        return find(node->left, key);
    } else {
        return find(node->right, key);
    }
}

template <typename K, typename V>
Node<K, V>* SortedDictionary<K, V>::erase(Node<K, V>* node, const K& key) {
    if (node == nullptr) {
        return nullptr;
    } else if (key < node->key) {
        node->left = erase(node->left, key);
    } else if (key > node->key) {
        node->right = erase(node->right, key);
    } else {
        if (node->left == nullptr) {
            Node<K, V>* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            Node<K, V>* temp = node->left;
            delete node;
            return temp;
        } else {
            Node<K, V>* temp = minValueNode(node->right);
            node->key = temp->key;
            node->values = temp->values;
            node->right = erase(node->right, temp->key);
        }
    }
    return node;
}

template <typename K, typename V>
Node<K, V>* SortedDictionary<K, V>::minValueNode(Node<K, V>* node) {
    Node<K, V>* current = node;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

template <typename K, typename V>
int SortedDictionary<K, V>::size(Node<K, V>* node) {
    if (node == nullptr) {
        return 0;
    } else {
        return size(node->left) + 1 + size(node->right);
    }
}
// ----------------- SORTED_DICTIONARY -----------------