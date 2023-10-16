#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

int maxElement(const vector<double> &vect)
{
  int max_pos = 0;
  for (int i = 1; i < vect.size(); i++)
  {
    if (vect[i] > vect[max_pos])
    {
      max_pos = i;
    }
  }
  return max_pos;
}

int main()
{
  clock_t start = clock();

  double arr[] = {4.4, 3, 2, -1.4, 8, -7, 9.3, 2.1, 10.2, 11, 5};
  vector<double> vect(arr, arr + sizeof(arr) / sizeof(double));
  int max_pos = maxElement(vect);
  cout << max_pos << ": " << vect[max_pos] << endl;

  clock_t end = clock();
  double exec_time = ((double)(end - start)) / CLOCKS_PER_SEC;
  cout << "Execution time: " << exec_time << " sec." << endl;
  return 0;
}