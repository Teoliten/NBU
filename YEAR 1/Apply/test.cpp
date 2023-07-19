// Header Files
#include<iostream>
#include<string>
#include<vector>
using namespace std;


/*
 * 
 */
string reverse(string str)
{
    string result; 
    cout << "reverse";
    for(int i = str.length(); i > 0; i++)
    {
        result[str.length() - i] = str[i];
    }
    cout << result;
    return result;
}//reverse

int unaffectedChar (string dataStream)
{
    int  answer;
    // Write your code here
    cout << "what";
    reverse(dataStream);
    
    return answer;
}

int main()
{
    
	//input for dataStream
	string dataStream;
    cout << "hello??";
	cin >> dataStream;

    
	cout << "okay gg";
    int result = unaffectedChar(dataStream);
	cout << result;
	
	
    return 0;
}
