#include <iostream>

using namespace std;

int makePartition(int arr[], int a, int b)
{
    int pivot = arr[a]; // choose the first element as the pivot
    int n = 0; // counter for elements smaller or equal to the pivot

    
    for (int i = a + 1; i <= b; i++)// count the number of elements smaller than or equal to the pivot
    {
        if (arr[i] <= pivot)
        {
            n++;
        }
    }

    int pivotIndex = a + n;
    swap(arr[pivotIndex], arr[a]); // swap the pivot with its correct position

    int i = a, j = b;

    
    while (i < pivotIndex && j > pivotIndex) // move the elements to their correct sides of the pivot
    {
        
        while (arr[i] <= pivot)// move the left pointer until an element greater than the pivot is found
        {
            i++;
        }

        while (arr[j] > pivot)// move the right pointer until an element smaller than or equal to the pivot is found
        {
            j--;
        }
        
        if (i < pivotIndex && j > pivotIndex)// swap the elements at i and j if they are on opposite sides of the pivot
        {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
} // makePartition

void quickSort(int arr[], int a, int b) // using tail recursion to perform quicksort
{
    if (a >= b) // base case
    {
        return; 
    }

    int part = makePartition(arr, a, b);

    // recursively sort the lower and upper halves
    quickSort(arr, a, part - 1); // sort the lower half
    quickSort(arr, part + 1, b); // sort the upper half
} // quickSort

void printArr(int arr[], int size)
{
    cout << "Array:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << endl << endl;
} // printArr

int main()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) // read array
    {
        cin >> arr[i];
    }

    int size = sizeof(arr) / sizeof(arr[0]); 

    cout << "Unsorted ";
    printArr(arr, size); // print the unsorted array

    quickSort(arr, 0, size - 1); // sort the array using quicksort

    cout << "Sorted ";
    printArr(arr, size); // print the sorted array

    return 0;
} // main
