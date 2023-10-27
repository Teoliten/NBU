#include <iostream>

using namespace std;

class DVector
{
public:
  DVector();
  DVector(const DVector &vect);
  ~DVector();
  DVector &operator=(const DVector &vect);
  //DVector &opearator[]();
  void resize(int cpct);
  void insert(int pos, int number);

  int size();
  bool empty();
  int at(int pos);
  void print();


private:
  int *ptr_arr;
  int cpct;
  int numb;
};

DVector::DVector() : cpct(0), numb(0), ptr_arr(nullptr) {}

DVector::DVector(const DVector &vect)
{
  cpct = vect.cpct;
  numb = vect.numb;

  ptr_arr = new int[cpct];

  for (int i = 0; i < numb; i++)
  {
    ptr_arr[i] = vect.ptr_arr[i];
  }
} // copy constructor?

DVector::~DVector()
{
  if (ptr_arr)
  {
    cout << "~";
    delete[] ptr_arr;
    ptr_arr = nullptr;
  }
} // destructor

DVector &DVector::operator=(const DVector &vect)
{
  this->resize(vect.numb);
  for(int i = 0; i < vect.numb; i++)
  {
    this->ptr_arr[i] = vect.ptr_arr[i];
  }
  return *this;
}

void DVector::resize(int cpct)
{
  if (cpct <= 0)
  {
    throw logic_error("...");
  }
  if (this->cpct < cpct)
  {
    int* ptr_new_arr = new int[cpct];
    for (int i = 0; i < numb; i++)
    {
      ptr_new_arr[i] = ptr_arr[i];
    }
    //free();
    ptr_arr = ptr_new_arr;
    this->cpct = cpct;
  }
} // resize

void DVector::insert(int pos, int number)
{
  if (pos < 0 || pos > numb)
  {
    throw out_of_range("...");
  }

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

int DVector::size()
{
  return numb;
}//size

bool DVector::empty()
{
  return (numb <= 0 ? true : false);
}//empty
  
int DVector::at(int pos)
{
  return ptr_arr[pos];
}//at

void DVector::print()
{
  for(int i = 0; i < numb; i++)
  {
    cout << ptr_arr[i] << " ";
  }
  cout << endl;
  cout << this->cpct << endl;
}

int main()
{
  DVector dv;
  dv.insert(0, 5);
  dv.insert(1, 5);
  cout << "SIZE: " << dv.size() << endl;
  dv.resize(5);
  cout << "AT: " << dv.at(1) << endl;
  dv.print();
  DVector dv2;
  dv2 = dv;

  cout << endl << "dv2: ";
  dv2.print();
  
  return 0;
} // main