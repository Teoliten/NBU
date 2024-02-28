#include <iostream>

using namespace std;
//---------------NODE---------------
class Node
{
public:
    Node(int data);
    int get_data();

private:
    int data;
    Node* ptr_prev;
    Node* ptr_next;

friend class Dequeue;
};//Node

Node::Node(int data)//default parameter constructor
{
    this->data = data;
    ptr_prev = nullptr;
    ptr_next = nullptr;
}//Node

int Node::get_data()
{
    return data;
}//get_data
//---------------NODE---------------

//---------------DEQUEUE---------------
class Dequeue
{
public:
    Dequeue();
    ~Dequeue();

    void push_back(int data);
    void push_front(int data);

    void pop_back();
    void pop_front();

    void print();

private:
    Node* ptr_frst;
    Node* ptr_last;

friend class Node;
};//Dequeue
//________________________________
Dequeue::Dequeue()//default contructor
{
    ptr_frst = nullptr;
    ptr_last = nullptr;
}//Dequeue

Dequeue::~Dequeue()//deconstructor
{
    Node* ptr_del = ptr_frst;
    ptr_frst = ptr_frst->ptr_next;

    delete ptr_del;
    ptr_del = nullptr;
}//~Dequeue
//________________________________
void Dequeue::push_back(int data)
{
    Node* ptr_new = new Node(data);
    if(!ptr_frst)
    {
        ptr_frst = ptr_new;
        ptr_last = ptr_new;
    }
    else
    {
        ptr_new->ptr_prev = ptr_last;
        ptr_last->ptr_next = ptr_new;
        ptr_last = ptr_new;
    }
}//push_back

void Dequeue::push_front(int data)
{
    Node* ptr_new = new Node(data);
    if(!ptr_frst)
    {
        ptr_frst = ptr_new;
        ptr_last = ptr_new;
    }
    else
    {
        ptr_new->ptr_next = ptr_frst;
        ptr_frst->ptr_prev = ptr_new;
        ptr_frst = ptr_new;
    }
}//push_front
//________________________________
void Dequeue::pop_back()
{
    if(!ptr_frst)//No nodes in Dequeue
    {
        cout << "No nodes in to remove in Dequeue" << endl;
    }
    else
    {
        Node* ptr_del = ptr_last;
        ptr_last = ptr_last->ptr_prev;
        if(ptr_last == nullptr)
        {
            ptr_frst = nullptr;
        }
        else
        {
            ptr_last->ptr_next = nullptr;
        }
        delete ptr_del;
        ptr_del = nullptr;
    }
}//pop_back

void Dequeue::pop_front()
{
    if(!ptr_frst)//No nodes in Dequeue
    {
        cout << "No nodes in to remove in Dequeue" << endl;
    }
    else
    {
        Node* ptr_del = ptr_frst;
        ptr_frst = ptr_frst->ptr_next;
        if(ptr_frst == nullptr)
        {
            ptr_last = nullptr;
        }
        else
        {
            ptr_frst->ptr_prev = nullptr;
        }
        delete ptr_del;
        ptr_del = nullptr;
    }
}//pop_front
//________________________________

void Dequeue::print()
{
    Node* printN = ptr_frst;
    if(ptr_frst == nullptr)
    {
        cout << "Empty Dequeue." << endl;
    }
    while(printN != nullptr)
    {
        cout << printN->get_data() << " ";
        printN = printN->ptr_next;
    }
    cout << endl;
}//print

//---------------DEQUEUE---------------

int main()
{
    Dequeue dq;
    dq.push_front(42);  // 42
    dq.print();
    
    dq.push_back(2);    // 42 + 2
    dq.print();

    dq.pop_front();     // -42 2 -> 2
    dq.push_front(1);   // +1 2
    dq.push_back(3);    // 1 2 +3
    dq.push_back(4);    // 1 2 3 +4
    dq.print();

    dq.pop_front();     // -1 2 3 4 -> 2 3 4
    dq.print();

    dq.pop_front();     // -2 3 4 -> 3 4
    dq.print();
    
    dq.pop_back();      // 3 -4 -> 3
    dq.print();
    
    return 0;
}//main