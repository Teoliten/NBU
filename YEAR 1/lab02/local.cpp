#include <iostream>

using namespace std;

int* foo(int *ptr)
{
	//int bar;

	return ptr;
}//foo

int main()
{
	int bar = 0;
	int* ptr = foo(&bar);

	cout << ptr << endl;

	return 0;
}//main
