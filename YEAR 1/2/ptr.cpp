#include <iostream>

using namespace std;

int main()
{
	int var = 42;
	int* ptr = &var;
	cout << "Memory location: " << ptr << endl;
	cout << "Value using the pointer: " << (*ptr) << endl;
	
	// change the value of the variable
	(*ptr) = 0;
	
	cout << "Value using the pointer: " << (*ptr) << endl;
	cout << "Value using the variable: " << var << endl;

	return 0;
}//main
