#include <iostream>
#include <string>
#include <sstream>

using namespace std;

inline string covert(char op)
{
	string result; 
	switch(op)
	{
	case '+':
		result  = "sum";
		break;
	case '-':
		result  = "subtraction";
		break;
	case '*':
		result  = "multiplication";
		break;
	case '/':
		result  = "division";
		break;
	default:	
		result = "unknown operation";
	}
	return result;
}//covert

string parse(const string &expr)
{
	istringstream in_strm(expr);
	int l_oper;
	in_strm >> l_oper;
	char op;
    in_strm >> op;
    cout << op << endl;

	return covert(op);

}//parse

int main()
{
	cout << "Simple arithmetical expression:";
	string expr;
	cin >> expr;
    cout << parse(expr) << endl;
	return 0;
}//main