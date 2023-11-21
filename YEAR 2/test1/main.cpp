#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print(const vector<int> vctr) // print vector
{
  for (int i = 0; i < vctr.size(); i++)
  {
    cout << vctr[i] << " ";
  }
  cout << endl
       << endl;
} // print

void swapVal(vector<int> &vctr, int pos1, int pos2)
{
  int tmp = vctr[pos1];
  vctr[pos1] = vctr[pos2];
  vctr[pos2] = tmp;
} // swapVal

int partition(vector<int> &vctr, int front, int end)
{
  int pivot = vctr[front];

  int count = 0; // amount of numbers greater then pivot element
  for (int i = (front + 1); i <= end; i++)
  {
    if (vctr[i] <= pivot)
    {
      count++;
    }
  }

  int index = front + count; // pos to have space for numbers > pivot on left, number < pivot on right
  swapVal(vctr, index, front);

  int l = front;
  int k = end;

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

void quickSort(vector<int> &vctr, int front, int end) // quicksort vector
{
  if (front >= end)
  {
    return;
  }

  int part = partition(vctr, front, end);

  quickSort(vctr, front, part - 1);
  quickSort(vctr, part + 1, end);
} // quickSort

void removeDuplicates(vector<int> &vctr)
{
  vector<int> result;
  result.push_back(vctr[0]);
  int prev = vctr[0];

  for (int i = 1; i < vctr.size(); i++)
  {
    if (vctr[i] == prev)
    {
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

  for (int i = 0; i < input.length(); i++) // read input into vector
  {
    if (i % 2)
    {
      continue;
    }
    else
    {
      vctr.push_back(input[i] - 48); // char to int
    }
  }

  cout << endl
       << "Given vector: ";
  print(vctr);

  quickSort(vctr, 0, (vctr.size() - 1)); // (vector, front, back)
  cout << "Sorted vector (using quickSort): ";
  print(vctr);

  removeDuplicates(vctr);
  cout << "Duplicates removed from sorted vector: ";
  print(vctr);

  return 0;
} // main