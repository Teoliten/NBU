#include <iostream>

using namespace std;

class DVector
{
public:
  DVector();
  DVector(const DVector &vect);
  ~DVector();
  DVector &operator=(const DVector &vect);
  // DVector &opearator[]();
  void resize(int cpct);
  void insert(int pos, int number);

private:
  int *ptr_arr;
  int cpct;
  int numb;
};

DVector::DVector() : cpct(0), numb(0), ptr_arr(nullptr) {}

DVector::DVector(const DVector &vect)
{
  copy(vect);
} // copy constructor?

DVector::~DVector()
{
  free();
} // destructor

DVector &DVector::operator=(const DVector &vect)
{
  // delete old, create new of same size, copy elements into new one.
  return *this;
}

void DVector::resize(int cpct)
{
  if (this->cpct < cpct)
  {
    int *ptr_new_arr = new int[cpct];
    for (int i = 0; i < cpct; i++)
    {
      ptr_new_arr[i] = ptr_arr[i];
    }
    free();
    ptr_arr = ptr_new_arr;
    this->cpct = cpct;
  }
} // resize

void DVector::insert(int pos, int number)
{
  if (numb >= cpct)
  {
    resize(max(1, cpct << 1));
  }
  for (int i = numb - 1; i >= pos; i--)
  {
    ptr_arr[i + 1] = ptr_arr[i];
  }
  ptr_arr[pos] = number;
  numb++;
} // insert

int main()
{
  return 0;
} // main