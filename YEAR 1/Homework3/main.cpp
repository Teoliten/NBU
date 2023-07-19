#include <iostream>

using namespace std;

#include "QuadraticInt.h"

void testNoCopy(const QuadraticInt &z)
{
	cout << endl << "h: " << z;
}//testNoCopy

void testCopy(const QuadraticInt z)
{
	cout << "h: " << z;
}//testCopy

int main()
{
	
	cout << endl << "---------| (a) the difference between initialization and assignment |---------" << endl;
	QuadraticInt s;
	cout << "Initialization: " << "QuadraticInt t = s;" << endl;
	QuadraticInt t = s;
	cout << "^ Triggers" << endl;
	
	cout << endl << "Assignment operation: " << endl << "QuadraticInt q;";
	cout << endl << "QuadraticInt w;" << endl;
	cout << "q = w;" << endl;
	QuadraticInt q;
	QuadraticInt w;
	q = w;
	cout << "^ is triggered" << endl;
	cout << "---------------------------------------------------------------" << endl;
	
	cout << "Member function which calculates the value of a quadratic function for a given argument value:" << endl;
	cout << "s: ";
	cin >> s;
	cout << endl << "Solving \"s\" for argument value: 3" << endl;
	s.solveQ(3);
	cout << "---------------------------------------------------------------" << endl;

	//showing s*s
	cout << "Quadratic equation \"s\" has real roots (1 = true, 0 = false): ";
	cout << s*s << endl;
	cout << "---------------------------------------------------------------" << endl;

	//showing << / >>
	QuadraticInt j;
	cout << "Reading \"QuadraticInt j;\" using overloaded \">>\":" << endl << "cin >> j;" << endl;
	cin >> j;
	cout << "Printing \"j\" using overloaded \"<<\":" << endl << "cout << j;" << endl;
	cout << j;
	cout << "---------------------------------------------------------------" << endl;
	
	//showing s + t
	cout << "Addition of two polynomials with overloaded \"+\"" << endl;
	cout << s + j;
	
	//showing s - t
	cout << "Subtraction of two polynomials with overloaded \"-\"" << endl;
	cout << s - j;
	cout << "---------------------------------------------------------------" << endl;

	cout << "Copy constructor:" << endl;
	QuadraticInt h(j);
	cout << h;

	cout << endl << "No copy triggered when passing by reference (const QuadraticInt &z)";
	testNoCopy(h);

	cout << endl<< "Copy triggering when passing by value (const QuadraticInt z)";
	testCopy(h);

	cout << endl << "END OF MAIN" << endl;
	cout << "---------------------------------------------------------------" << endl;
	cout << "Automatic Destruction:";
	return 0;
}//main