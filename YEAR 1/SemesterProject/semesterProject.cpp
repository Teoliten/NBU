/*
Task:
implement a class template List that represents a fully-functioning singly-linked list. 
The list much be implemented as a singly linked sequence of dynamically created nodes.
The list much be have functions to insert/delete in the middle of the list as well.

default constructor
constructor with parameters;
copy constructor
destructor
overloaded assigment operator
append, insert, delete capabilities
*/
#include <iostream>
#include <cassert>

using namespace std;
//-------------NODE-------------
template <typename T>
class Node
{
    public:
        Node(const T& data);//parameter constructor
        T data;             //data in node of type T
        Node* ptr_next;     //pointer to next node in list
};//class Node

template <typename T>
Node<T>::Node(const T& data)
{
    this->data = data;
    this->ptr_next = nullptr;
}//Node
//-------------NODE-------------

//-------------LIST-------------
template <typename T>
class List
{
    public:
        List();                 //default constructor
        List(const List &z);    //copy constructor
        ~List();                //destructor

        void append(T& val);    //append data
        void insert(int pos, T& data);//intert value
        void pop(const int pos);//delete value
        void print();           //print elements of list

        List& operator =(const List &z);//overloaded assignment opeartor

    private:
        Node<T>* ptr_frst;      //pointer to last node in list
        Node<T>* ptr_last;      //pointer to last node in list
        int size;               //size of list
};//class List

template <typename T>
List<T>::List()//default constructor
{
	ptr_frst = nullptr;
	ptr_last = nullptr;
	size = 0;
}//List

template <typename T>
List<T>::List(const List &z)//copy constructor
{
    ptr_frst = nullptr;
    ptr_last = nullptr;
    size = 0;

    Node<T>* curr = z.ptr_frst;
    while(curr)
    {
        append(curr->data);
        curr = curr->ptr_next;
    }
}//List copy

template <typename T>
List<T>::~List()//destructor
{
    cout << "Destructor" << endl;
    while(ptr_frst)
    {
        Node<T>* ptr_tmp = ptr_frst;
        ptr_frst = ptr_frst->ptr_next;
        delete ptr_tmp;
        ptr_tmp = nullptr;
    }
}//~List

template <typename T>
void List<T>::append(T& data)//add data to end
{
    Node<T>* ptr_newn = new Node<T>(data);
    if(ptr_last)
    {
        ptr_last->ptr_next = ptr_newn;
    }
    else
    {
        ptr_frst = ptr_newn;
    }
    ptr_last = ptr_newn;
    size++;
}//append

template <typename T>
void List<T>::insert(int pos, T& data)//insert element at given position
{
    assert(pos <= size + 1);
    Node<T>* ptr_newn = new Node<T>(data);
    Node<T>* curr = ptr_frst;
    Node<T>* ptr_prev = nullptr;

    for(int i = 0; i < pos; i++)//looping until we are at the right position
    {
        ptr_prev = curr;
        curr = curr->ptr_next;
    }

    if(ptr_prev == nullptr)//inserting in the front
    {
        ptr_newn->ptr_next = ptr_frst;
        ptr_frst = ptr_newn;
        if(ptr_last == nullptr)
        {
            ptr_last = ptr_newn;
        }
    }
    else if(curr == nullptr)//iserting in the end
    {
        ptr_prev->ptr_next = ptr_newn;
        ptr_last = ptr_newn;
        ptr_newn->ptr_next = nullptr;
    }
    else//insert in middle
    {
        ptr_prev->ptr_next = ptr_newn;
        ptr_newn->ptr_next = curr;
    }
    size++;
}//insert

template <typename T>
void List<T>::pop(const int pos)//delete element at given position
{
    assert(ptr_frst);
    assert(pos <= size);
    Node<T>* curr = ptr_frst;
    Node<T>* ptr_prev = ptr_frst;
    for(int i = 0; i < pos; i++)//going along the list until we are at the position where we want to delete the node
    {
        curr = curr->ptr_next;
        if(i < pos-1)
        {
            ptr_prev = ptr_prev->ptr_next;
        }
    }

    if(curr == ptr_frst)//popping first element
    {
        ptr_frst = ptr_frst->ptr_next;
        delete curr;
        curr = nullptr;
    }
    else if(curr == ptr_last)//poppint last element
    {
        ptr_prev->ptr_next = nullptr;
        ptr_last = ptr_prev;
        delete curr;
        curr = nullptr;
    }
    else//popping element in the middle
    {
        ptr_prev->ptr_next = curr->ptr_next;
        delete curr;
        curr = nullptr;
    }
    size--;
}//pop

template <typename T>
void List<T>::print()
{
    Node<T>* curr = ptr_frst;
    while(curr)//while != nullptr
    {
        cout << curr->data << ", ";
        curr = curr->ptr_next;
    }
    cout << endl;
}//print

template <typename T>
List<T>& List<T>::operator =(const List &z)
{
    if(this != &z)
	{
		Node<T>* curr = ptr_frst;
		while(curr)//if old exist, delete all elements
		{
			Node<T>* ptr_next = curr->ptr_next;
			delete curr;
			curr = ptr_next;
		}
		//copy all elements from z to this.
		ptr_frst = nullptr;
		ptr_last = nullptr;
		size = 0;
		curr = z.ptr_frst;
		while(curr)//while theres still more elements to add, push current data and then do next element
		{
			append(curr->data);
			curr = curr->ptr_next;
		}
	}
	return *this;
}//operator =

//-------------LIST-------------

//-------------MAIN-------------
int main()
{
    List<int> l;
    for(int i = 1; i < 6; i++)
    {
        l.append(i);
    }
    l.print();
    int number = 42;
    l.insert(1, number);
    l.print();

    l.pop(4);
    l.print();
    int add = 2;
    l.append(add);
    l.print();
    l.pop(2);
    l.print();
    cout << "q: ";
    List<int> q(l);
    q.append(number);
    q.append(number);
    q.print();

    q = l;
    q.print();

    return 0;
}//main
//-------------MAIN-------------