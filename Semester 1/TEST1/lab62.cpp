#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> permutations(const string &word)
{
    vector<string> result;

    if(word.length() == 1)
    {
        result.push_back(word);
    }
    else
    {
        for(int i = 0; i < word.length(); i++)
        {
            string sub = word.substr(0, i) + word.substr(i + 1);
            vector<string> sub_perm = permutations(sub);
            for(int j = 0; j < sub_perm.size(); j++)
            {
                string perm = word[i] + sub_perm[j];
                result.push_back(perm);
            }
        }
    }
    return result;
}

void print(const vector<string> &perm)
{
    for(int i = 0; i < perm.size(); i++)
    {
        cout << perm[i] << " ";
    }
    cout << endl;
}

int main()
{
    cout << "Enter a string: ";
    string inp;
    cin >> inp;

    vector<string> perm = permutations(inp);
    print(perm);

    return 0;
}//main