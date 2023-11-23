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
// Abstract base class representing the concept of numerical progression
class Progression
{
public:
  Progression(long start = 0) : current(start) {}

  // Returns the first value in the progression
  long firstValue();

  // Pure virtual function representing the generation of the next value in the progression
  virtual long nextValue() = 0;

protected:
  long current;
}; // Progression

// Returns the first value in the progression
long Progression::firstValue()
{
  return current;
} // firstValue
//---------------------Progression---------------------



//---------------------ArithmeticPr--------------------
// Derived class representing arithmetic progression: N, add V every iteration
class ArithmeticPr : public Progression
{
public:
  ArithmeticPr(long start = 0, long value = 1) : Progression(start), value(value) {}

  // Generates the next value in the arithmetic progression by adding the common difference
  long nextValue();

private:
  long value; // Common difference
}; // ArithmeticPr

// Generates the next value in the arithmetic progression by adding the common difference
long ArithmeticPr::nextValue()
{
  current += value;
  return current;
} // nextValue
//---------------------ArithmeticPr--------------------



//---------------------GeometricPr---------------------
// Derived class representing geometric progression: Non-zero number, multiply by variable
class GeometricPr : public Progression
{
public:
  GeometricPr(long start = 0, long value = 1) : Progression(start), value(value) {}

  // Generates the next value in the geometric progression by multiplying the common ratio
  long nextValue();

private:
  long value; // Common ratio
}; // GeometricPr

// Generates the next value in the geometric progression by multiplying the common ratio
long GeometricPr::nextValue()
{
  current *= value;
  return current;
} // nextValue
//---------------------GeometricPr---------------------



//---------------------HarmonicPr----------------------
// Derived class representing harmonic progression: For N sequence, 1, 2, 3, 4, 5, 6...
class HarmonicPr : public Progression
{
public:
  HarmonicPr(long start = 1) : Progression(start) {}

  // Generates the next value in the harmonic progression
  long nextValue();
}; // HarmonicPr

// Generates the next value in the harmonic progression
long HarmonicPr::nextValue()
{
  current++;
  return current;
} // nextValue
//---------------------HarmonicPr----------------------



//---------------------main----------------------
// Main function to demonstrate the progression classes
int main()
{
  // Create instances of each progression
  ArithmeticPr ap(5, 1); // Start at 5, addition with 1 each time.
  GeometricPr gp(10, 2); // Start at 10, multiply with 2 each time.
  HarmonicPr hp(1);      // Start at 1, 1/2, 1/3, 1/4, 1/5 etc.

  // Generate and print the first 5 values in each progression
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
//---------------------main----------------------