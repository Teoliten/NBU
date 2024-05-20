#include <bits/stdc++.h>

using namespace std;

bool checkWord(string subWord, vector<string> &words)
{
  for (int i = 0; i < words.size(); i++)
  {
    if (subWord == words[i])
    {
      words[i] = "0";
      return true;
    }
  }

  return false;
}

string split(string input, vector<string> words)
{
  // cout << "start" << endl;
  string result = "";

  bool wordFound = false;
  int wordLen = 0;

  for (int i = 0; i < input.length(); i = i)
  {
    string subWord = "";
    for (int j = 1; j < input.length(); j++)
    {
      wordFound = false;
      subWord = input.substr(i, j);
      if (checkWord(subWord, words))
      {
        wordFound = true;
        wordLen = subWord.length();
        i += wordLen;
        result.append(subWord + " ");
        break;
      }
    }
    if (!wordFound)
    {
      result = "false";
      return result;
    }
  }

  return result;
}

int main()
{
  int T;
  cin >> T;
  while (T--)
  {
    int n;
    cin >> n;
    string input;
    cin >> input;

    vector<string> words;
    for (int i = 0; i < n; i++)
    {
      string word;
      cin >> word;
      words.push_back(word);
    }

    cout << "result: " << split(input, words) << endl;
  }

  return 0;
}