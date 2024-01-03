#include <iostream>

using namespace std;

#include "priorityQueue.h"

template <typename typeElement, typename typeCompare>
void printMin(const typeElement &frst, const typeElement &scnd, typeCompare &isLess)
{
  cout << (isLess(frst, scnd) ? frst : scnd) << endl;
} // printMin

int main()
{
  // Using compareLexi for lexicographical order
  PriorityQueue<string, compareLexi> pq_lexi;
  pq_lexi.push("Morty");
  pq_lexi.push("Rick");
  pq_lexi.push("Evil_Morty");
  pq_lexi.push("Meesix");

  pq_lexi.printQueue(); // print using printQueue function

  //_________________________________________

  // Using compareInt for numerical order
  PriorityQueue<string, compareInt> pq_int;
  pq_int.push("20");
  pq_int.push("100");
  pq_int.push("30");
  pq_int.push("15");
  // pq_int.push("Q"); // runtime_error: "Can't convert to integer."

  while (!pq_int.empty()) // print using "".empty", ".top" and ".pop"
  {
    cout << pq_int.top() << " ";
    pq_int.pop();
  }
  cout << endl;

  return 0;
} // main
