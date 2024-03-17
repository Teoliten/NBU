#include <iostream>
#include <vector>

using namespace std;

void swapPos(int a, int b, vector<int> &arr)
{
  int tmp = arr[a];
  arr[a] = arr[b];
  arr[b] = tmp;
}

void sortArray(vector<int> &arr)
{
  int two_pos = arr.size() - 1;
  int one_pos = 0;
  for (int i = 0; i < arr.size(); i++)
  {
    if (arr[i] == 2 && i < two_pos)
    {
      swapPos(i, two_pos, arr);
      two_pos--;
    }

    if (arr[i] == 1 && i < one_pos)
    {
      swapPos(i, one_pos, arr);
      two_pos--;
    }
  }
}

int main()
{
  vector<int> arr = {0, 2, 2, 0, 0};
  sortArray(arr);

  cout << "Sorted array: ";
  for (int i = 0; i < arr.size(); i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}
