#include <iostream>

using namespace std;

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
        indx_frnt = (indx_frnt + 1) % CPCT;
        numb--;
    }
}//dequeue
//AQueue

int main()
{
    AQueue<int> aq;
    aq.size();
    return 0;
}//main