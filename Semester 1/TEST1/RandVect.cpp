#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

#include "RandVect.h"

void randVect(vector<int> &vect, int min, int max)
{
	for (int i = 0; i < vect.size(); i++)
	{
		vect[i] = min + rand() % (max - min + 1); 
	}		
}//randVect

void printVect(vector<int> &vect)
{
	for (int i = 0; i < vect.size(); i++)
	{
		cout << vect[i] << " ";
	}	
	cout << endl;
}//printVect
