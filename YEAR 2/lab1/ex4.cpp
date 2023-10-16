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

void prefixAvrg(const vector<double> &inp, vector<double> &avrg)
{
  avrg.resize(inp.size());

  for (int i = 0; i < inp.size(); i++)
  {
    avrg[i] = 0;
    for (int j = 0; j <= i; j++)
    {
      avrg[i] += inp[j];
    }
    avrg[i] /= (i + 1);
  }
}

int main()
{
  clock_t start = clock();

  double arr[] = {44, 3, 25, -14, 8};
  vector<double> vect(arr, arr + sizeof(arr) / sizeof(double));
  int max_pos = maxElement(vect);
  cout << max_pos << ": " << vect[max_pos] << endl;
  vector<double> avrg;
  prefixAvrg(vect, avrg);

  for (int i = 0; i < avrg.size(); i++)
  {
    cout << avrg[i] << " ";
  }
  cout << endl;

  clock_t end = clock();
  double exec_time = ((double)(end - start)) / CLOCKS_PER_SEC;
  cout << "Execution time: " << exec_time << " sec." << endl;
  return 0;
}