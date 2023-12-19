#include <iostream>

using namespace std;

// ----------Node----------
class Node
{
public:
    Node(int value);
    int getData();
    Node* ptr_next;

private:
    int data;
};

Node::Node(int value)
{
    data = value;
    ptr_next = nullptr;
}

int Node::getData()
{
    return data;
}
// ----------Node----------

// ----------queue----------
class queue
{
public:
    queue();
    ~queue();

    void enqueue(int value);
    void dequeue();

    void print();

private:
    int size;

    Node* ptr_front;
    Node* ptr_back;
};

queue::queue()
{
    ptr_front = nullptr;
    ptr_back = nullptr;
    size = 0;
}

queue::~queue()
{
    while(ptr_front)
    {
        Node* ptr_tmp = ptr_front;
        ptr_front = ptr_front->ptr_next;
        delete ptr_tmp;
    }
}

void queue::enqueue(int value)
{
    Node* ptr_node = new Node(value);
    if(!size)
    {
        ptr_front = ptr_node;
        ptr_back = ptr_node;
    }
    else
    {
        ptr_back->ptr_next = ptr_node;
        ptr_back = ptr_node;
    }
    size++;
}

void queue::dequeue()
{
    if(size)
    {
        Node* ptr_tmp = ptr_front;
        ptr_front = ptr_front->ptr_next;
        delete ptr_tmp;
        size--;
    }
}

void queue::print()
{
    Node* ptr_current = ptr_front;
    cout << "Queue: ";
    while(ptr_current != nullptr)
    {
        cout << ptr_current->getData() << " ";
        ptr_current = ptr_current->ptr_next;
    }
    cout << endl;
}
// ----------queue----------

// ----------main----------
int main()
{
    queue q;
    q.enqueue(5);
    q.enqueue(1);
    q.enqueue(2);
    q.print();
    q.dequeue();
    q.print();
    q.enqueue(11);
    q.print();

    return 0;
}
// ----------main----------
