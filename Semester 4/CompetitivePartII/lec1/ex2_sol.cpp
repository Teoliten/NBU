#include <iostream>
#include <vector>

using namespace std;

int *aSort(int *a, int n)
{
  int low = 0, mid = 0, high = n - 1;

  while (mid <= high)
  {
    switch (a[mid])
    {
    case 0:
      swap(a[low], a[mid]);
      low++;
      mid++;
      break;
    case 1:
      mid++;
      break;
    case 2:
      swap(a[mid], a[high]);
      high--;
      break;
    }
  }
  return a;
}

int main()
{
  int n;
  // int *a = (int *)malloc(sizeof(int) * n); // allocate space for specific area
  int *a = new int[n];

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  for (int i = 0; i < n; i++)
  {
    cout << a[i] << "/t";
  }

  a = aSort(a, n);
  return 0;
}