#include <iostream>

using namespace std;

class SVector
{
public:
  SVector(); // default constructor
  void set(int pos, int number);
  int at(int pos);
  int size();
  bool empty();
  void insert(int pos, int number);
  void erase(int pos);

private:
  enum
  {
    CPCT = 256
  };
  int arr[CPCT];
  int numb;
};

SVector::SVector()
{
  numb = 0;
  for (int i = 0; i < CPCT; i++)
  {
    arr[i] = 0;
  }
} // SVector

void SVector::set(int pos, int number)
{
  if (pos < 0 || pos >= numb)
  {
    throw out_of_range("...");
  }
  arr[pos] = number;
} // set

int SVector::at(int pos)
{
  if (pos < 0 || pos >= numb)
  {
    throw out_of_range("...");
  }
  return arr[pos];
} // at

int SVector::size()
{
  return numb;
} // size

bool SVector::empty()
{
  return (numb == 0) ? true : false;
} // empty

void SVector::insert(int pos, int number)
{
  for (int i = numb - 1; i > pos; i++)
  {
    arr[i + 1] = arr[i];
  }
  arr[pos] = number;
  numb++;
} // insert

void SVector::erase(int pos)
{
  for (int i = pos; i < numb; i++)
  {
    arr[i] = arr[i + 1];
  }
} // erase

int main()
{
  SVector sv;
  sv.insert(0, 5);
  cout << sv.empty();
  return 0;
}