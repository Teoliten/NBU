// Header Files
#include<iostream>
#include<string>
#include<vector>

#include <cmath> // abs()

using namespace std;

string intToBin(int num)
{
    if (num == 0) {
        return "0";
    }

    string result = "";
    while(num > 0)
    {
        if(num % 2 == 0)
            result = "0" + result;
        else
            result = "1" + result;

    num /= 2;
    }
    
    return result;
}

int flippedBits (int num1, int num2)
{
    string bin1 = intToBin(num1);
    string bin2 = intToBin(num2);
    int len1 = bin1.length();
    int len2 = bin2.length();

    int diff = abs(len1 - len2);
    string addZero = "";
    for(int i = 0; i < diff; i++)
    {
        addZero += "0";
    }
    
    if(len1 > len2)    
        bin2 = addZero + bin2;
    else
        bin1 = addZero + bin1;
    
    cout << "res" << bin1 << endl;
    cout << "res" << bin2 << endl;
    int answer = 0;

    if(bin1.length() == bin2.length())
    {
        for(int i = 0; i < len1; i++)
        {
            if(!(bin1[i] == bin2[i]))
            {
                answer++;
            }
        }
    }
    
    
    return answer;
}

int main()
{
    //input for num1
	int num1 = 8;
	// cin >> num1;

	//input for num2
	int num2 = 82;
	// cin >> num2;
	
	
    int result = flippedBits(num1, num2);
	cout << result;
	
	
    return 0;
}
