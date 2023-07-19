#include <iostream>
#include <string>

using namespace std;

const int SIZE = 256;

void copyStr(const char str1[], char str3[])
{
    int j = 0;
    while(str1[j] != '\0' && j < SIZE)
    {
        str3[j] = str1[j];
        j++;
    }
    str3[j] = '\0';

    cout << endl << "New third string copied from first string: " << str3 << endl << endl;
}//copyStr

void charStr(char str1[], char str2[])
{
    int i = 0;
    int length1 = 0;
    while(str1[i] != '\0')
    {
        i++;
    }
    length1 = i;

    i = 0;
    int length2 = 0;
    while(str2[i] != '\0')
    {
        i++;
    }
    length2 = i;
    
    cout << endl << "First string length is " << length1 << "." << endl;
    cout << "Second string length is " << length2 << "." << endl;
}//charStr

void printStr(char str1[], char str2[])
{
    cout << endl << "First string: " << str1 << endl << "Second string: " << str2 << endl;
}//printStr

void readStr(char str1[], char str2[])
{
    cout << "Enter first string." << endl << "> ";
    cin >> str1;
    
    cout << "Enter second string." << endl << "> ";
    cin >> str2;

}//readStr

int main()
{
    char* str1 = NULL;
    str1 = new char[SIZE];

    char* str2 = NULL;
    str2 = new char[SIZE];

    readStr(str1, str2);
    
    printStr(str1, str2);

    charStr(str1, str2);

    char* str3 = NULL;
    str3 = new char[SIZE];
    copyStr(str1, str3);
    

    if(str1 != nullptr)
    {
        delete[] str1;
        str1 = nullptr;
        cout << "log: Deleting: str1" << endl;
    }
    if(str2 != nullptr)
    {
        delete[] str2;
        str2 = nullptr;
        cout << "log: Deleting: str2" << endl;
    }
    if(str3 != nullptr)
    {
        delete[] str3;
        str3 = nullptr;
        cout << "log: Deleting: str3" << endl;
    }
    return 0;
}//main