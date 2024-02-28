#include <iostream>

using namespace std;

template <typename T1, typename T2>
class Pair
{
    public:
        Pair();//default constructor
        Pair(const T1& first, const T2& second);
        void setFirst(const T1 &first);
        void setSecond(const T2& second);
        T1 getFirst() const;
        T2 getSecond() const;

    private:
        T1 first;
        T2 second;
};

template <typename T1, typename T2>
inline Pair<T1, T2>::Pair(const T1& first, const T2& second)//parameter constructor
{
    this->first = first;
    this->second = second;
}

template <typename T1, typename T2>
void Pair<T1, T2>::setFirst(const T1 &first)
{
    this->first = first; 
}//setfirst

template <typename T1, typename T2>
void Pair<T1, T2>::setSecond(const T2 &second)
{
    this->second = second; 
}//setSecond

template <typename T1, typename T2>
T1 Pair<T1, T2>::getFirst() const
{
    return first;
}//getfirst

template <typename T1, typename T2>
T2 Pair<T1, T2>::getSecond() const
{
    return second;
}//getsecond



int main()
{
    Pair<int, string> p(5, "Hello, World!");
    p.setFirst(5);
    
    cout << p.getFirst();
    cout << endl << p.getSecond();
    return 0;
}//main