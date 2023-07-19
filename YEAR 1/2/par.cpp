#include <iostream>

using namespace std;

void foo1(int a)
{
	a = 0;
}//foo1

void foo2(int &a)
{
	a = 0;
}//foo2

void foo3(int* ptr)
{
	*ptr = 0;
}//foo3

int main()
{
	int var = 42;
	cout << "Before foo1: " << var << endl;
	foo1(var);
	cout << "After foo1: " << var << endl;

	cout << "Before foo2: " << var << endl;
	foo2(var);
	cout << "After foo2: " << var << endl;

	var = 42;
	
	cout << "Before foo2: " << var << endl;
	foo3(&var);
	cout << "After foo2: " << var << endl;


	return 0;
}//main
