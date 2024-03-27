#include <iostream>

using namespace std;

int makePartition(int arr[], int a, int b)
{
  int pivot = arr[a];
  int n = 0;

  for (int i = a + 1; i <= b; i++)
  {
    if (arr[i] <= pivot)
    {
      n++;
    }
  }

  int pivotIndex = a + n;
  swap(arr[pivotIndex], arr[a]);

  int i = a, j = b;

  while (i < pivotIndex && j > pivotIndex)
  {

    while (arr[i] <= pivot)
    {
      i++;
    }

    while (arr[j] > pivot)
    {
      j--;
    }

    if (i < pivotIndex && j > pivotIndex)
    {
      swap(arr[i++], arr[j--]);
    }
  }

  return pivotIndex;
} // makePartition

void quickSort(int arr[], int a, int b)
{
  if (a >= b)
  {
    return;
  }

  int part = makePartition(arr, a, b);

  quickSort(arr, a, part - 1);

  quickSort(arr, part + 1, b);
} // quickSort

void printArr(int arr[], int size)
{
  cout << "Array:" << endl;
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << ", ";
  }
  cout << endl
       << endl;
} // printArr

int main()
{
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  int size = sizeof(arr) / sizeof(arr[0]);

  cout << "Unsorted ";
  printArr(arr, size);

  quickSort(arr, 0, size - 1);

  cout << "Sorted ";
  printArr(arr, size);

  return 0;
} // main