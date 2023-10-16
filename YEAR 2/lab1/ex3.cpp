#include <iostream>
#include <ctime>
#include <vector>
#include <cstdlib>

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

void randVect(vector<double> &vect, double min, double max)
{
  for (int i = 0; i < vect.size(); i++)
  {
    vect[i] = (std::rand() % max) + min; //
  }
}

int main()
{
  int MIN_SIZE = 0, MAX_SIZE = 0;
  cout << "Min vect size: ";
  cin >> MIN_SIZE;

  cout << endl
       << "Max vect size: ";
  cin >> MAX_SIZE;

  cout << endl
       << "Min vect value: ";
  double MIN_VAL = 0, MAX_VAL = 0;
  cin >> MIN_VAL;
  cout << endl
       << "Max vect value: ";
  cin >> MAX_VAL;
  cout << endl;

  for (int i = MIN_SIZE; i <= MAX_SIZE; i++)
  {
    vector<double> vect(i);
    randVect(vect, MIN_VAL, MAX_VAL);
    cout << "Vect: ";
    for (int k = MIN_SIZE; k < MAX_SIZE; k++)
    {
      cout << vect[k] << " ";
    }
    cout << endl;
    // clock_t start = clock();
    int max_pos = maxElement(vect);
    // clock_t end = clock();
    // double exec_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << max_pos << ": " << vect[max_pos] << endl;
    cout << endl;
    // cout << "Execution time: " << exec_time << " sec." << endl
    //<< endl;
  }
  return 0;
}