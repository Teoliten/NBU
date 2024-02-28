#ifndef CLIST_H
#define CLIST_H

struct Node
{
  int data;
  Node *ptr_next;
};

class Clist
{
public:
  Clist();              // Default contructor
  ~Clist();             // Destructor
  void add(int data);   // Add an element in the list
  int front() const;    // Return the front
  int back() const;     // Return the back
  void advance();       // Advance the cursor
  bool isEmpty() const; // Check if list is empty
  void remove();        // Remove after cursor
private:
  Node *ptr_crsr;
};

#endif