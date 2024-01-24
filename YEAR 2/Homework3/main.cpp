#include <iostream>
#include <utility>

using namespace std;

template <typename Key, typename Value>
class SortedDictionary {
public:
    struct Node {
        Key key;
        Value value;
        Node* left;
        Node* right;

        Node(const Key& k, const Value& v) : key(k), value(v), left(nullptr), right(nullptr) {}
    };


private:
    Node* root;

public:
    SortedDictionary() : root(nullptr) {}

    ~SortedDictionary() {
        clear(root);
    }

    // Function to recursively clear the tree
    void clear(Node* node) {
        if (node) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }
    
    // Function to insert a key-value pair into the dictionary
    void insert(const Key& key, const Value& value) {
        root = insert(root, key, value);
    }

    Node* insert(Node* node, const Key& key, const Value& value) {
        if (!node) {
            return new Node(key, value);
        }

        if (key < node->key) {
            node->left = insert(node->left, key, value);
        } else if (key > node->key) {
            node->right = insert(node->right, key, value);
        } else {
            // Key already exists, update the value
            node->value = value;
        }

        return node;
    }

    // Function to get the number of entries in the dictionary
    size_t size() const {
        return size(root);
    }

    size_t size(Node* node) const {
        return node ? 1 + size(node->left) + size(node->right) : 0;
    }

    // Function to check if the dictionary is empty
    bool empty() const {
        return root == nullptr;
    }

    // Function to find an iterator to the entry with key k, or the sentinel if k is not present
    Node* find(const Key& key) const {
        return find(root, key);
    }

    Node* find(Node* node, const Key& key) const {
        while (node) {
            if (key < node->key) {
                node = node->left;
            } else if (key > node->key) {
                node = node->right;
            } else {
                return node;
            }
        }

        return nullptr; // Key not found
    }

    // Function to find a pair of iterators (b, e) for all entries with key k
    pair<Node*, Node*> findAll(const Key& key) const {
        Node* first = nullptr;
        Node* last = nullptr;
        findAll(root, key, first, last);
        return make_pair(first, last);
    }

    void findAll(Node* node, const Key& key, Node*& first, Node*& last) const {
        if (!node) {
            return;
        }

        if (key < node->key) {
            findAll(node->left, key, first, last);
        } else if (key > node->key) {
            findAll(node->right, key, first, last);
        } else {
            // Key found, update first and last
            if (!first) {
                first = node;
            }
            last = node;

            // Search in the left subtree for potential additional entries
            findAll(node->left, key, first, last);

            // Search in the right subtree for potential additional entries
            findAll(node->right, key, first, last);
        }
    }

    // Function to erase by key
    void erase(const Key& key) {
        root = erase(root, key);
    }

    Node* erase(Node* node, const Key& key) {
        if (!node) {
            return nullptr;
        }

        if (key < node->key) {
            node->left = erase(node->left, key);
        } else if (key > node->key) {
            node->right = erase(node->right, key);
        } else {
            // Node to be deleted found

            // Case 1: Node with only one child or no child
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            // Case 2: Node with two children
            // Find the inorder successor (smallest node in the right subtree)
            Node* successor = minValueNode(node->right);

            // Copy the inorder successor's content to this node
            node->key = successor->key;
            node->value = successor->value;

            // Delete the inorder successor
            node->right = erase(node->right, successor->key);
        }

        return node;
    }
    
    Node* minValueNode(Node* node) const {
        Node* current = node;

        // Find the leftmost leaf node
        while (current && current->left) {
            current = current->left;
        }

        return current;
    }

    // Function to erase by iterator
    void erase(Node* iteratorToDelete) {
        if (iteratorToDelete) {
            root = erase(root, iteratorToDelete->key);
        }
    }

    Node* erase(Node* rootNode, Node* targetNode) {
        if (!rootNode) {
            return nullptr;
        }

        if (targetNode->key < rootNode->key) {
            rootNode->left = erase(rootNode->left, targetNode);
        } else if (targetNode->key > rootNode->key) {
            rootNode->right = erase(rootNode->right, targetNode);
        } else {
            // Node to be deleted found

            // Case 1: Node with only one child or no child
            if (!rootNode->left) {
                Node* temp = rootNode->right;
                delete rootNode;
                return temp;
            } else if (!rootNode->right) {
                Node* temp = rootNode->left;
                delete rootNode;
                return temp;
            }

            // Case 2: Node with two children
            // Find the inorder successor (smallest node in the right subtree)
            Node* successor = minValueNode(rootNode->right);

            // Copy the inorder successor's content to this node
            rootNode->key = successor->key;
            rootNode->value = successor->value;

            // Delete the inorder successor
            rootNode->right = erase(rootNode->right, successor);
        }

        return rootNode;
    }

    // Function to get an iterator to the beginning
    Node* begin() const {
        return minValueNode(root);
    }

    // Function to get an iterator to the end
    Node* end() const {
        return nullptr;
    }
};

int main() {
    SortedDictionary<int, string> dictionary;

    // Inserting values into the dictionary
    dictionary.insert(5, "Five");
    dictionary.insert(3, "Three");
    dictionary.insert(7, "Seven");
    dictionary.insert(2, "Two");
    dictionary.insert(4, "Four");
    dictionary.insert(6, "Six");
    dictionary.insert(8, "Eight");

    // Adding entries with the same key
    dictionary.insert(5, "Another Five");
    dictionary.insert(7, "Another Seven");

    // Printing size and checking if empty
    cout << "Size: " << dictionary.size() << endl;
    cout << "Is empty: " << (dictionary.empty() ? "Yes" : "No") << endl;

    // Finding entries by key
    int keyToFind = 4;
    SortedDictionary<int, string>::Node* foundNode = dictionary.find(keyToFind);

    if (foundNode) {
        cout << "Found: Key = " << foundNode->key << ", Value = " << foundNode->value << endl;
    } else {
        cout << "Key not found." << endl;
    }

    // Finding all entries with a key
    pair<SortedDictionary<int, string>::Node*, SortedDictionary<int, string>::Node*> range =
        dictionary.findAll(keyToFind);

    if (range.first) {
        SortedDictionary<int, string>::Node* current = range.first;
        while (current) {
            cout << "Found: Key = " << current->key << ", Value = " << current->value << endl;
            current = current->right;
        }
    } else {
        cout << "Key not found." << endl;
    }

    // Erasing by key
    dictionary.erase(3);

    // Erasing by iterator
    SortedDictionary<int, string>::Node* iteratorToDelete = dictionary.find(5);
    dictionary.erase(iteratorToDelete);

    // Printing the dictionary after erasing
    cout << "Size after erasing: " << dictionary.size() << endl;

    // Iterating through the dictionary
    cout << "Entries in ascending order:" << endl;
    SortedDictionary<int, string>::Node* iterator = dictionary.begin();
    while (iterator) {
        cout << "Key = " << iterator->key << ", Value = " << iterator->value << endl;
        iterator = iterator->right;
    }

    return 0;
}
