#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include <stdexcept>

template <typename TKey, typename TValue>
class Dictionary
{
private:
    struct TreeNode
    {
        TKey key;
        TValue value;
        TreeNode* left;
        TreeNode* right;

        TreeNode(const TKey& k, const TValue& v)
            : key(k), value(v), left(nullptr), right(nullptr) {}
    };

    TreeNode* root;

    // Helper functions for recursive operations
    TreeNode* put(TreeNode* node, const TKey& key, const TValue& value);
    TreeNode* find(TreeNode* node, const TKey& key);
    TreeNode* erase(TreeNode* node, const TKey& key);
    void clear(TreeNode* node);
    void inorderTraversal(TreeNode* node) const;

public:
    class Iterator;

    Dictionary();
    ~Dictionary();

    Iterator put(const TKey& key, const TValue& value);
    Iterator find(const TKey& key);
    bool erase(const TKey& key);
    bool erase(Iterator& iterator);
    Iterator begin() const;
    Iterator end() const;
    int size() const;
    bool empty() const;
};

template <typename TKey, typename TValue>
class Dictionary<TKey, TValue>::Iterator
{
public:
    Iterator(TreeNode* node) : current(node) {}

    Iterator& operator++(); // Pre-increment
    const TKey& getKey() const;
    const TValue& getVal() const;

private:
    TreeNode* current;
};

// Implement the member functions...

// Constructor
template <typename TKey, typename TValue>
Dictionary<TKey, TValue>::Dictionary() : root(nullptr) {}

// Destructor
template <typename TKey, typename TValue>
Dictionary<TKey, TValue>::~Dictionary()
{
    clear(root);
}

// Helper function for recursive clear
template <typename TKey, typename TValue>
void Dictionary<TKey, TValue>::clear(TreeNode* node)
{
    if (node)
    {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

// Helper function for recursive put
template <typename TKey, typename TValue>
typename Dictionary<TKey, TValue>::TreeNode* Dictionary<TKey, TValue>::put(TreeNode* node, const TKey& key, const TValue& value)
{
    if (!node)
    {
        return new TreeNode(key, value);
    }

    if (key < node->key)
    {
        node->left = put(node->left, key, value);
    }
    else if (key > node->key)
    {
        node->right = put(node->right, key, value);
    }
    else
    {
        node->value = value; // Update existing node
    }

    return node;
}

// Helper function for recursive find
template <typename TKey, typename TValue>
typename Dictionary<TKey, TValue>::TreeNode* Dictionary<TKey, TValue>::find(TreeNode* node, const TKey& key)
{
    if (!node || key == node->key)
    {
        return node;
    }

    if (key < node->key)
    {
        return find(node->left, key);
    }
    else
    {
        return find(node->right, key);
    }
}

// Helper function for recursive erase
template <typename TKey, typename TValue>
typename Dictionary<TKey, TValue>::TreeNode* Dictionary<TKey, TValue>::erase(TreeNode* node, const TKey& key)
{
    if (!node)
    {
        return nullptr;
    }

    if (key < node->key)
    {
        node->left = erase(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = erase(node->right, key);
    }
    else
    {
        // Node with the key found, perform deletion
        if (!node->left)
        {
            TreeNode* temp = node->right;
            delete node;
            return temp;
        }
        else if (!node->right)
        {
            TreeNode* temp = node->left;
            delete node;
            return temp;
        }

        // Node with two children: Get the inorder successor
        TreeNode* successor = node->right;
        while (successor->left)
        {
            successor = successor->left;
        }

        // Copy the inorder successor's data to this node
        node->key = successor->key;
        node->value = successor->value;

        // Delete the inorder successor
        node->right = erase(node->right, successor->key);
    }

    return node;
}

// Helper function for recursive inorder traversal
template <typename TKey, typename TValue>
void Dictionary<TKey, TValue>::inorderTraversal(TreeNode* node) const
{
    if (node)
    {
        inorderTraversal(node->left);
        std::cout << "(" << node->key << ": " << node->value << ") ";
        inorderTraversal(node->right);
    }
}

// Member function to insert a key-value pair
template <typename TKey, typename TValue>
typename Dictionary<TKey, TValue>::Iterator Dictionary<TKey, TValue>::put(const TKey& key, const TValue& value)
{
    root = put(root, key, value);
    return Iterator(find(root, key));
}

// Member function to find a key in the dictionary
template <typename TKey, typename TValue>
typename Dictionary<TKey, TValue>::Iterator Dictionary<TKey, TValue>::find(const TKey& key)
{
    return Iterator(find(root, key));
}

// Member function to erase a key from the dictionary
template <typename TKey, typename TValue>
bool Dictionary<TKey, TValue>::erase(const TKey& key)
{
    bool erased = erase(root, key) != nullptr;
    return erased;
}

// Member function to erase using an iterator
template <typename TKey, typename TValue>
bool Dictionary<TKey, TValue>::erase(Iterator& iterator)
{
    if (iterator.getKey() != TKey()) // Check if the iterator is not at the end
    {
        root = erase(root, iterator.getKey());
        iterator = Iterator(find(root, iterator.getKey()));
        return true;
    }
    return false;
}

// Member function to return the iterator to the first element in the list
template <typename TKey, typename TValue>
typename Dictionary<TKey, TValue>::Iterator Dictionary<TKey, TValue>::begin() const
{
    TreeNode* current = root;
    while (current && current->left)
    {
        current = current->left;
    }
    return Iterator(current);
}

// Member function to return the iterator to the sentinel entry
template <typename TKey, typename TValue>
typename Dictionary<TKey, TValue>::Iterator Dictionary<TKey, TValue>::end() const
{
    return Iterator(nullptr);
}

// Member function to return the size of the Dictionary
template <typename TKey, typename TValue>
int Dictionary<TKey, TValue>::size() const
{
    // You may need to implement this based on your specific requirements
    // For a binary search tree, this could be computed by traversing the tree.
    // However, this implementation does not keep track of size for simplicity.
    return -1;
}

// Member function to check whether the Dictionary is empty
template <typename TKey, typename TValue>
bool Dictionary<TKey, TValue>::empty() const
{
    return root == nullptr;
}

// Member function for pre-increment operator of Iterator
template <typename TKey, typename TValue>
typename Dictionary<TKey, TValue>::Iterator& Dictionary<TKey, TValue>::Iterator::operator++()
{
    // Implement this based on in-order traversal
    // You may need to maintain additional state to keep track of the traversal.
    return *this;
}

// Member function to get the key of the current iterator
template <typename TKey, typename TValue>
const TKey& Dictionary<TKey, TValue>::Iterator::getKey() const
{
    if (current)
    {
        return current->key;
    }
    else
    {
        // Return a default-constructed key as a sentinel for the end iterator
        static TKey defaultKey;
        return defaultKey;
    }
}

// Member function to get the value of the current iterator
template <typename TKey, typename TValue>
const TValue& Dictionary<TKey, TValue>::Iterator::getVal() const
{
    if (current)
    {
        return current->value;
    }
    else
    {
        // Return a default-constructed value as a sentinel for the end iterator
        static TValue defaultValue;
        return defaultValue;
    }
}

#endif