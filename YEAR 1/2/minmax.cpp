#include <iostream>

using namespace std;

const int SIZE = 8;

void readArr(double arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << i << ": ";
		cin >> *(arr + i); // arr[i]
	}
}//readArr

void minmax(double* arr, int size, double* min, double* max)
{
	*min = *arr;
	*max = *arr;
	for (int i = 1; i < size; i++)
	{
		if (*(arr + i) < *min)
		{
			*min = *(arr + i); // arr[i]
		}
		if (*(arr + i) > *max)
		{
			*max = *(arr + i);
		}		
	}
}//minmax

int main()
{
	double arr[SIZE];

	readArr(arr, SIZE);
	double min, max;
	minmax(arr, SIZE, &min, &max);

	cout << "Min: " << min << "\t\tMax: " << max << endl;

	return 0;
}//main
