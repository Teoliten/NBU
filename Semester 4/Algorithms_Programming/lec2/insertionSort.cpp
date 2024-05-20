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

void insertionSort(int arr[], int size)
{
  int key, j;
  for (int i = 1; i < size; i++) // Start from the second element
  {
    key = arr[i];
    j = i - 1;
    while (j >= 0 && arr[j] > key)
    {
      arr[j + 1] = arr[j]; // Shift elements to the right
      j--;
    }
    arr[j + 1] = key; // Place the key in its correct position
    // printArr(arr, size);
  }
} // insertionSort

int main()
{
  int arr[] = {1, 5, 2, 8, 11, 1, 2, 0};
  int size = sizeof(arr) / sizeof(arr[0]);

  insertionSort(arr, size);
  printArr(arr, size);

  return 0;
}