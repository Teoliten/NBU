#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

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
}

// ----------------- NODE -----------------

// ----------------- ITERATOR -----------------
template <typename K, typename V>
class SortedDictionaryIterator {
private:
    using Node = Node<K, V>;

    Node* current;
    stack<Node*> nodes;

public:
    SortedDictionaryIterator(Node* root) : current(root) {
        // Move to the leftmost node
        while (current) {
            nodes.push(current);
            current = current->left;
        }

        // Set current to the leftmost node
        if (!nodes.empty()) {
            current = nodes.top();
            nodes.pop();
        }
    }

    // Overload the pre-increment operator (++iterator)
    SortedDictionaryIterator& operator++() {
        // Move to the next node in in-order traversal
        if (current->right) {
            current = current->right;
            while (current) {
                nodes.push(current);
                current = current->left;
            }
        } else if (!nodes.empty()) {
            current = nodes.top();
            nodes.pop();
        } else {
            current = nullptr; // End of traversal
        }

        return *this;
    }

    // Overload the dereference operator (*iterator)
    pair<const K&, vector<V>&> operator*() const {
        return make_pair(current->key, current->values);
    }

    // Overload the arrow operator (iterator->)
    pair<const K&, vector<V>&> operator->() const {
        return **this;
    }

    // Overload the equality operator (iterator == iterator)
    bool operator==(const SortedDictionaryIterator& other) const {
        return current == other.current;
    }

    // Overload the inequality operator (iterator != iterator)
    bool operator!=(const SortedDictionaryIterator& other) const {
        return !(*this == other);
    }
};

// ----------------- ITERATOR -----------------

// ----------------- SORTED_DICTIONARY -----------------
template <typename K, typename V>
class SortedDictionary {
    Node<K, V>* root;

public:
    SortedDictionary();

    // Insert a key-value pair into the tree
    void insert(const K& key, const V& value);

    // Find a key in the tree
    Node<K, V>* find(const K& key);

    // Erase a key from the tree
    void erase(const K& key);

    // Check if the tree is empty
    bool empty() const;

    // Get the size of the tree
    int size() const;

    using Iterator = SortedDictionaryIterator<K, V>;

    Iterator begin() const {
        return Iterator(minValueNode(root));
    }

    Iterator end() const {
        return Iterator(nullptr);
    }

private:
    Node<K, V>* insert(Node<K, V>* node, const K& key, const V& value);

    Node<K, V>* find(Node<K, V>* node, const K& key);

    Node<K, V>* erase(Node<K, V>* node, const K& key);

    Node<K, V>* minValueNode(Node<K, V>* node) const;

    int size(Node<K, V>* node) const;
};

// SortedDictionary member functions
template <typename K, typename V>
SortedDictionary<K, V>::SortedDictionary(){
    this->root = nullptr; // Initialize the root of the dictionary to nullptr
}

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
bool SortedDictionary<K, V>::empty() const {
    return root == nullptr;
}

template <typename K, typename V>
int SortedDictionary<K, V>::size() const {
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
Node<K, V>* SortedDictionary<K, V>::minValueNode(Node<K, V>* node) const {
    Node<K, V>* current = node;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

template <typename K, typename V>
int SortedDictionary<K, V>::size(Node<K, V>* node) const {
    if (node == nullptr) {
        return 0;
    } else {
        return size(node->left) + 1 + size(node->right);
    }
}
// ----------------- SORTED_DICTIONARY -----------------
