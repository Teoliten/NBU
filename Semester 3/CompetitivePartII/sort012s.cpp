#include <iostream> //cout <<
#include <random>   //srand, rand
#include <vector>   //vector

using namespace std;

void printV(vector<int> v)
{
  for (int i = 0; i < v.size(); ++i)
  {
    cout << v[i] << " ";
  }
  cout << endl;
} // printV

void sort(vector<int> &array)
{
  int zeros = 0;
  int ones = 0;
  int twos = 0;

  for (int i = 0; i < array.size(); i++)
  {
    if (array[i] == 0)
      zeros++;

    if (array[i] == 1)
      ones++;

    if (array[i] == 2)
      twos++;
  }

  // cout << zeros << ones << twos << endl;
  for (int i = 0; i < zeros; i++)
    array[i] = 0;

  for (int i = zeros; i < zeros + ones; i++)
    array[i] = 1;

  for (int i = zeros + ones; i < zeros + ones + twos; i++)
    array[i] = 2;
}

int main()
{
  srand(time(NULL));

  vector<int> array;
  for (int i = 0; i < 20; i++) // generate vector with 20 entries, containing 0, 1 or 2
  {
    array.push_back(rand() % 3);
  }
  cout << "List: ";
  printV(array);

  sort(array); // sort with coplexity O(n)

  printV(array);
  return 0;
} // main