#include <iostream>

using namespace std;

//throws
class QueueFull : public runtime_error
{
    public:
        QueueFull(const string &m) : runtime_error(m) {}
};

class QueueEmpty : public runtime_error
{
    public:
        QueueEmpty(const string &m) : runtime_error(m) {}
};
//throws

//AQueue
template <typename T>
class AQueue
{
    public:
        AQueue();
        void enqueue(const T &e);
        void dequeue();
        const T &front() const;
        int size() const;
        bool empty() const;

    private:
        enum {CPCT = 256};
        T arr[CPCT];
        int indx_frnt;
        int indx_rear;
        int numb;
};//AQueue

template <typename T>
AQueue<T>::AQueue()
{
    indx_frnt = 0;
    indx_rear = 0;
    numb = 0;
}//AQueue

template <typename T>
const T &AQueue<T>::front() const
{
    if(numb == 0)
    {
        throw QueueEmpty("QueueEmpty");
    }
    return arr[indx_frnt];
}//front

template <typename T>
int AQueue<T>::size() const
{
    return numb;
}//size

template <typename T>
bool AQueue<T>::empty() const
{
    return numb == 0;
}//empty

template <typename T>
void AQueue<T>::enqueue(const T &e)
{
    if(numb == CPCT)
    {
        throw QueueFull("QueueFull");
    }
    arr[indx_rear] = e;
    indx_rear = (indx_rear + 1) % CPCT;
    numb++;
}//enqueue

template <typename T>
void AQueue<T>::dequeue()
{
    if(numb == 0)
    {
        throw QueueEmpty("QueueEmpty");
    }
    indx_frnt = (indx_frnt + 1) % CPCT;
    numb--;
}//dequeue
//AQueue



int main()
{
    AQueue<int> aq;

    aq.enqueue(42); // Enqueue an element
    try 
    {
        aq.dequeue(); // Attempt to dequeue
    } 
    catch (const QueueEmpty& e) 
    {
        cerr << "Queue is empty: " << e.what() << endl;
    }
    return 0;
}