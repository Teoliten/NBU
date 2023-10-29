/*
Implement a class Progression that represents
the concept of numerical progression. The class
Progression must be an abstract class that is used
as a base class in inheritance hierarchy that must
include classes for arithmetic progression, geometric
progression, and harmonic progression. Show polymorphism.
*/

#include <iostream>

using namespace std;

//---------------------Progression---------------------
class Progression // Base class
{
public:
  Progression(long start = 0) : current(start) {}

  long firstValue();

  virtual long nextValue() = 0;

protected:
  long current;
}; // Progression

long Progression::firstValue()
{
  return current;
} // firstValue
//---------------------Progression---------------------

//---------------------ArithmeticPr--------------------
class ArithmeticPr : public Progression // N, add V every iteration, ex, N = 5, v = 1: 5, 6, 7, 8, 9, 10.
{
public:
  ArithmeticPr(long start = 0, long value = 1) : Progression(start), value(value) {}

  long nextValue();

private:
  long value;
}; // ArithmeticPr

long ArithmeticPr::nextValue()
{
  current += value;
  return current;
} // nextValue
//---------------------ArithmeticPr--------------------

//---------------------GeometricPr---------------------
class GeometricPr : public Progression // Non-zero number, multiply by variable. Multiply previous with same variable over again. ex, n = 5. v = 3: 5, 5*3, 15*3, 45*3: 5 15, 45, 135.
{
public:
  GeometricPr(long start = 0, long value = 1) : Progression(start), value(value) {}

  long nextValue();

private:
  long value;
}; // GeometricPr

long GeometricPr::nextValue()
{
  current *= value;
  return current;
} // nextValue
//---------------------GeometricPr---------------------

//---------------------HarmonicPr----------------------
class HarmonicPr : public Progression // For N sequece, 1, 2, 3, 4, 5, 6: Harmonic progression: 1/1, 1/2, 1/3, 1/4, 1/5, 1/6.
{
public:
  HarmonicPr(long start = 1) : Progression(start) {}

  long nextValue();
}; // HarmonicPr

long HarmonicPr::nextValue()
{
  current++;
  return current;
} // nextValue
//---------------------HarmonicPr----------------------

int main()
{
  ArithmeticPr ap(5, 1); // Start at 5, addition with 1 each time.
  GeometricPr gp(10, 2); // Start at 10, multiply with 2 each time.
  HarmonicPr hp(1);      // Start at 1, 1/2, 1/3, 1/4, 1/5 etc.

  // Generate and print the first 5 values in the progressions
  cout << "Arithmetic Progression (First five values): ";
  for (int i = 1; i <= 5; i++)
  {
    cout << ap.firstValue() << " ";
    ap.nextValue();
  }
  cout << endl;

  cout << "Geometric Progression (First five values): ";
  for (int i = 1; i <= 5; i++)
  {
    cout << gp.firstValue() << " ";
    gp.nextValue();
  }
  cout << endl;

  cout << "Harmonic Progression (First five values): ";
  for (int i = 1; i <= 5; i++)
  {
    cout << "1/" << hp.firstValue() << " ";
    hp.nextValue();
  }
  cout << endl;

  return 0;
} // main
