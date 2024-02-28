#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

#include "RandVect.h"

inline void swap(int &frst, int &scnd)
{
	int tmp = frst;
	frst = scnd;
	scnd = tmp;
}//swap

void selectSort(vector<int> &vect)
{
	int last = vect.size() - 1;
	for (int indx_sub = 0; indx_sub < last; indx_sub++)
	{
		int indx_min = indx_sub;
		for (int indx_curr = indx_sub; 
				indx_curr < vect.size(); indx_curr++)
		{
			if (vect[indx_curr] < vect[indx_min])
			{
				indx_min = indx_curr;
			}
		} 
		if (indx_sub != indx_min)
		{
			swap(vect[indx_sub], vect[indx_min]);
		}
	}
}//selectSort

void merge(vector<int> &vect, int from, int mid, int to)
{
	vector<int> tmp(to - from + 1);
	int indx_frst = from;
	int indx_scnd = mid + 1;
	
	int indx_tmp;
	for (indx_tmp = 0; indx_frst <= mid && indx_scnd <= to; indx_tmp++)
	{
		tmp[indx_tmp] =
			(vect[indx_frst] < vect[indx_scnd]) ?
				vect[indx_frst++] :
				vect[indx_scnd++];
	}

	while (indx_frst <= mid)
	{
		tmp[indx_tmp++] = vect[indx_frst++];
	}
	
	while (indx_scnd <= to)
	{
		tmp[indx_tmp++] = vect[indx_scnd++];
	}

	for (int indx_m = 0; indx_m < tmp.size(); indx_m++)
	{
		vect[from + indx_m] = tmp[indx_m];
	}
}//merge

void mergeSort(vector<int> &vect, int from, int to)
{
	if (from == to)
	{
		return;
	}
	int mid = (from + to) / 2;
	mergeSort(vect, from, mid);
	mergeSort(vect, mid + 1, to);
	merge(vect, from, mid, to);
}//mergeSort

void experiment(int start, int end)
{
	const int MIN_VAL = 1;
	const int MAX_VAL = 100;

	for (int size = start; size <= end; size *= 2)
	{
		vector<int> vect(size);	
		randVect(vect, MIN_VAL, MAX_VAL);
		time_t start_time = time(0);
		//sort(vect.begin(), vect.end());
		mergeSort(vect, 0, vect.size() - 1);
		time_t end_time = time(0);
		double exec_time = difftime(end_time, start_time);
		cout << "Size: " << size << "\t";
		cout << "Time: " << exec_time << endl;		 
	}
}//experiment

int main()
{
	const int START = 10;
	const int END = 10000;
	
	experiment(START, END);

	return 0;
}//main
