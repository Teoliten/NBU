#include <iostream>
#include <string>

using namespace std;

//swap
void swap(char &first, char &second)
{
    char tmp;
    tmp = first;
    first = second;
    second = tmp;
}

//reverse a string
void strrev(string &str)
{
    int i = 0;
    int j = str.length() - 1;
    while(i < j)
    {
        swap(str[i++], str[j--]);
    }
    
}



int main()
{
    while(!cin.fail())
    {
        string str;
        getline(cin, str);
        strrev(str);
        cout << str << endl;
    }

    return 0;
}//main

//g++ -o reverse reverse.cpp && ./reverse < input.txt > output.txt