#include <iostream>

using namespace std;
//----------------NODE----------------
class Node
{
    public:
        Node(int value);
    private:
        int value;
        Node* prev;
        Node* next;

    friend class LList;
};//Node

Node::Node(int value)
{
    this->value = value;
    prev = nullptr;
    next = nullptr;
}//Node
//----------------NODE----------------

//----------------List----------------
class LList
{
    public:
        class Iterator;
        LList();
        ~LList();

        void pushBack(int data);
        void insert(int data, int pos);

        Iterator begin();
        Iterator end();
        //Interator erase(Iterator ); //----------------------------------

    private:
        Node* first;
        Node* last;

    friend class Iterator;
};//LList

void LList::pushBack(int data)
{

}//pushBack

void LList::insert(int data, int pos)
{

}//insert
//----------------List----------------


//--------------Iterator--------------
class LList::Iterator
{
    public:
        Iterator();
        //Iterator(Node* pos...);
        //Iterator(const Iterator ...);
        //Iterator &operator =(...);
        Iterator &operator ++();
        Iterator operator ++(int);
        Iterator &operator --();
        Iterator operator --(int);
        int operator *() const;
        //bool operator !=(...) const;
    private:
        Node* pos;
        LList* count;

    friend class LList;

};
//--------------Iterator--------------

int main()
{
    LList l;


    return 0;
}//main