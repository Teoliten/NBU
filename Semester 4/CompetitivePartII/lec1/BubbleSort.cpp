#include <iostream>
#include <vector>
#include <random>

using namespace std;

void printV(vector<int> list)
{
  for (int i = 0; i < list.size(); ++i)
  {
    cout << list[i] << " ";
  }
  cout << endl;
}

void swap(vector<int> &list, int pos1, int pos2)
{
  int tmp = list[pos1];
  list[pos1] = list[pos2];
  list[pos2] = tmp;
} // swap

void bubbleSort(vector<int> &list)
{
  bool swapped;
  do
  {
    swapped = false;
    for (int i = 0; i < list.size() - 1; i++)
    {
      if (list[i] > list[i + 1])
      {
        swap(list, i, i + 1);
        swapped = true;
      }
    }
  } while (swapped);
} // bubbleSort

int main()
{
  // Generating random vector of length 5-20 with random variables from 0-20
  srand(time(NULL));

  int length = (rand() % 19 + 6); // 5 to 20
  vector<int> list(length);

  for (int i = 0; i < length; ++i)
  {
    list[i] = rand() % 21;
  }

  cout << "Randomly generated Vector: ";
  printV(list);

  bubbleSort(list);

  cout << "Bubble sorted Vector:      ";
  printV(list);
  return 0;
}
