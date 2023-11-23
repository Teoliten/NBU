#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to print the elements of a vector
void print(const vector<int> vctr)
{
  for (int i = 0; i < vctr.size(); i++)
  {
    cout << vctr[i] << " ";
  }
  cout << endl
       << endl;
} // print

// Function to swap two elements in a vector
void swapVal(vector<int> &vctr, int pos1, int pos2)
{
  int tmp = vctr[pos1];
  vctr[pos1] = vctr[pos2];
  vctr[pos2] = tmp;
} // swapVal

// Function to partition the vector for quicksort
int partition(vector<int> &vctr, int front, int end)
{
  int pivot = vctr[front];

  int count = 0; // Number of elements greater than the pivot

  for (int i = (front + 1); i <= end; i++)
  {
    if (vctr[i] <= pivot)
    {
      count++;
    }
  }

  int index = front + count; // Position for the pivot
  swapVal(vctr, index, front);

  int l = front;
  int k = end;

  // Partition the vector
  while (l < index && k > index)
  {
    while (vctr[l] <= pivot)
    {
      l++;
    }

    while (vctr[k] > pivot)
    {
      k--;
    }

    if (l < index && k > index)
    {
      swapVal(vctr, l, k);
      l++;
      k--;
    }
  }

  return index;
} // partition

// Function to perform quicksort on a vector
void quickSort(vector<int> &vctr, int front, int end)
{
  if (front >= end)
  {
    return;
  }

  int part = partition(vctr, front, end);

  // Recursively call quickSort on the partitions
  quickSort(vctr, front, part - 1);
  quickSort(vctr, part + 1, end);
} // quickSort

// Function to remove duplicates from a sorted vector
void removeDuplicates(vector<int> &vctr)
{
  vector<int> result;
  result.push_back(vctr[0]);
  int prev = vctr[0];

  // Iterate through the vector to remove duplicates
  for (int i = 1; i < vctr.size(); i++)
  {
    if (vctr[i] == prev)
    {
      // Duplicate found, do not add to the result vector
    }
    else
    {
      result.push_back(vctr[i]);
    }
    prev = vctr[i];
  }
  vctr = result;
} // removeDuplicates

int main()
{
  string input;
  getline(cin, input);

  vector<int> vctr;

  // Read input into the vector, converting characters to integers
  for (int i = 0; i < input.length(); i++)
  {
    if (i % 2)
    {
      continue;
    }
    else
    {
      vctr.push_back(input[i] - 48); // Convert char to int
    }
  }

  cout << endl
       << "Given Vector: ";
  print(vctr);

  // Sort the vector using quicksort
  quickSort(vctr, 0, (vctr.size() - 1));
  cout << "Sorted Vector (using Quicksort): ";
  print(vctr);

  // Remove duplicates from the sorted vector
  removeDuplicates(vctr);
  cout << "Duplicates removed from sorted vector: ";
  print(vctr);

  return 0;
} // main