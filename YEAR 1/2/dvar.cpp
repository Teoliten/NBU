#include <iostream>

using namespace std;

int main()
{
	int* ptr = new int;

	cout << "> ";
	cin >> *ptr;
	cout << "Value: " << *ptr << endl;

	delete ptr;

	return 0;
}//main
