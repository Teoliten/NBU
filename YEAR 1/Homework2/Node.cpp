#include "Node.h"

Node::Node(int data) {
    this->data = data;
    ptr_prev = nullptr;
    ptr_next = nullptr;
}

