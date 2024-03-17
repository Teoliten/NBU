#include <bits/stdc++.h>

using namespace std;

void printArr(int arr[], int size)
{
  cout << "Array: ";
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void mergeSort(int arr[], int const left, int const mid, int const right)
{
  int size = (sizeof(arr) / sizeof(arr[0]));
  if ((sizeof(arr) / sizeof(arr[0])) > 1)
  {
    int half = size / 2;
    // mergeSort(arr, );
  }
} // mergeSort

int main()
{
  int arr[] = {1, 5, 2, 8, 11, 1, 2, 0};
  int size = (sizeof(arr) / sizeof(arr[0]));
  printArr(arr, size);

  // mergeSort(arr);
  printArr(arr, size);

  return 0;
}