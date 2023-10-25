#include <iostream>

using namespace std;

//----------StackFull----------
class StackFull : public runtime_error
{
    public: 
    StackFull(const string &message) : runtime_error("Error: " + message)
    {
    }
    
};
//----------StackFull----------

//----------StackEmpty----------
class StackEmpty :
public runtime_error
{
    public:
    StackEmpty(const string &message): runtime_error("Error: " + message)
    {
    }
};
//----------StackEmpty----------

//----------AStack----------
template <typename T>
class AStack
{
    public:
        AStack();
        void push(const T &elmt);
        void pop();
        const T &top() const;
        int size() const;
        bool empty() const;
        void print() const;

    private:
        enum {CPCT = 256};
        T arr[CPCT];
        int indx_top;
};//AStack

template <typename T> 
AStack<T>::AStack()
{
    indx_top = -1;
}//AStack

template <typename T> 
void AStack<T>::push(const T &elmt)
{
    if(indx_top == CPCT - 1)
    {
        throw StackFull("Stack Full!");
    }
    arr[++indx_top] = elmt;
}//push

template <typename T> 
void AStack<T>::pop()
{
    if(indx_top < 0)
    {
        throw StackEmpty("Stack Empty!");
    }
    indx_top--;
}//pop

template <typename T>
void AStack<T>::print() const
{
    cout << "Stack: ";
    for(int i = 0; i <= indx_top; i++)
    {
        cout << arr[i] << " ";
    }
}//print
//----------AStack----------

int main()
{
    AStack<int> as;
    as.push(5);
    as.push(10);
    as.push(20);

    as.pop();
    as.pop();
    
    as.push(11);
    as.pop();

    as.print();

    return 0;
}//main