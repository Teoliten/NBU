#include <iostream>
#include <string>

using namespace std;

inline bool equalAlpha(char a, char b)
{
    return !((a - b) % ('a' - 'A'));
}

bool isPalin(const string &word)
{
    if(word.length() <= 1)
    {
        return true;
    }
    else
    {
        return equalAlpha(word[0], word[word.length()- 1] ) ? isPalin(word.substr(1, word.length()-2)): false;
    }
}

int main()
{
    cout << "Enter a string: ";
    string inp;
    cin >> inp;

    cout << 
        (isPalin(inp) ? "palindrome" : "not a palindrome") 
        << endl;

    return 0;
}//main