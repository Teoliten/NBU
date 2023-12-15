#include <iostream>
#include <string>
#include <sstream>

using namespace std;

//------------------------------
template <typename TElm, typename TCmp>
void printMin(const TElm &frst, const TElm &scnd, TCmp &isLess)
{
    cout << (isLess(frst, scnd) ? frst : scnd) << endl;
}//printMin
//------------------------------



//---------------PQueue---------------
template <typename TElm, typename TCmp>
class PQueue
{
public:
    int size() const;
    bool empty() const;
    void insert(const TElm &elm);
    const TElm &min() const;
    void removeMin();

private:
    list<TElm> llist;
    TCmp isLess;
};//Class PQueue

template <typename TElm, typename TCmp>
void PQueue<TElm, TCmp>::insert(const TElm &elm)
{
    typename list<TElm>::iterator iter;
    iter = llist.begin();
    while (iter != llist.end() && !isLess(elm, *iter))
    {
        ++iter;
    }
    llist.insert(iter, elm);
}//insert

//---------------PQueue---------------



//---------------CmpLexi---------------
class CmpLexi
{
public:
    bool operator()(const string &left, const string &right);
};//CmpLexi

bool CmpLexi::operator()(const string &left, const string &right)
{
    return left < right; 
}//operator ()
//---------------CmpLexi---------------



//---------------CmpInte---------------
class CmpInte
{
public:
    bool operator () (const string &left, const string &right);

private:
    int toInt(const string &str);
};//CmpInte

int CmpInte::toInt(const string &str)
{
    istringstream in_str_stream(str);
    int result;
    in_str_stream >> result;

    if(in_str_stream.fail())
    {
        throw runtime_error("...");
    }
    return result;
}//toInt

bool CmpInte::operator() (const string &left, const string &right)
{
    return toInt(left) < toInt(right);
}//operator ()
//---------------CmpLexi---------------



//---------------main---------------
int main()
{
    // Example using CmpLexi
    CmpLexi lexComparator;

    string str1 = "apple";
    string str2 = "banana";

    if (lexComparator(str1, str2))
        cout << str1 << " comes before " << str2 << " lexically." << endl;
    else
        cout << str2 << " comes before " << str1 << " lexically." << endl;


    // Example using CmpInte
    CmpInte intComparator;

    string numStr1 = "123";
    string numStr2 = "456";

    if (intComparator(numStr1, numStr2))
        cout << numStr1 << " is smaller than " << numStr2 << " numerically." << endl;
    else
        cout << numStr2 << " is smaller than " << numStr1 << " numerically." << endl;

    return 0;
}//main
//---------------main---------------
