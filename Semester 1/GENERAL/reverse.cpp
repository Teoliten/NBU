#include <iostream>
#include <string>

using namespace std;

string reverse(string a)
{
    int len = a.length();
    //cout << "len" << len << endl;
    int j = len - 1;
    string res = "     ";

    for(int i = 0; i < len; i++)
    {
        res[i] = a[j];
        j--;
        //cout << res << endl;
    }

    return res;
}

int main()
{
    cout << "enter INT number" << endl;
    string numb;
    cin >> numb;
    
    cout << reverse(numb);
    return 0;
}