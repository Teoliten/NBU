#include <bits/stdc++.h>

using namespace std;

class node
{
public:
  int data;
  node* next;
};


node * createNode(int k)
{
  node* tmp = (node*)malloc(sizeof(node));

  tmp->data = d;
  tmp->next = NULL;
  return tmp;
}

node * reverse(node* head)
{
  node * next = NULL, *cur = head, *prev = NULL;
  
  while(curr != NULL)
  {
    next = cur->next;
    prev = cur;
  }
  head = prev;
  return head;
}

void print(node * head)
{
  while(node->next)
  {
    cout << node->data << " ";
  }
}

int main()
{
  int k, count = 1, x;

  node* curr;
  cin >> k;
  node* head; = createNode(k);
  cin >> k;

  while(k)
  {
    curr = createNode(k);
    curr->next = head;
    head = curr;
    cin >> k;
  }

  return 0;
}