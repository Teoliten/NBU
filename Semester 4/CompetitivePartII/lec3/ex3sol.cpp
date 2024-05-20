#include <iostream>

using namespace std;

class node {
public:
    int data;
    node* next;
};

node* createNode(int d) {
    node* tmp = new node();
    tmp->data = d;
    tmp->next = NULL;
    return tmp;
}

node* reverse(node* head) {
    node *next = NULL, *cur = head, *prev = NULL;

    while (cur != NULL) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    head = prev;
    return head;
}

void print(node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int k;
    cin >> k;
    node* head = createNode(k);
    node* curr = head;

    while (cin >> k && k) {
        curr->next = createNode(k);
        curr = curr->next;
    }

    cout << "Original list: ";
    print(head);

    head = reverse(head);

    cout << "Reversed list: ";
    print(head);

    return 0;
}
