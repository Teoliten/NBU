// Header Files
#include<iostream>
#include<string>
#include<vector>
using namespace std;


/*
 * 
 */
void reverse(string &str)
{
    int len = str.length();
    for(int i = 0; i < len/2; i++)
    {
        char tmp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = tmp;
    }
}//reverse

int unaffectedChar (string dataStream)
{
    int  answer;
    // Write your code here
    string copy = dataStream;
    reverse(dataStream);
    
    int repeated = 0;

    for(int i = 0; i < dataStream.length(); i++)
    {
        if(copy[i] == dataStream[i])
        {
            repeated++;
        }
    }

    answer = repeated;

    return answer;
}

int main()
{
    
	//input for dataStream
	string dataStream;
	getline(cin,dataStream);
	
    int result = unaffectedChar(dataStream);
	cout << result;
	
	
    return 0;
}
