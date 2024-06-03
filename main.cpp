#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *next = NULL;
}

class LinkedList {
    public:
        Node *head = NULL;

        void add(int d) {
            if (head == NULL) {
                head->data = d;
                head->next = NULL;
            } else {
                int counter = 0;
                Node *ptr = head;
                Node *newNode = new Node;
                newNode->data = d;
                newNode->next = NULL;
                while (ptr->next != NULL) {
                    counter++;
                    ptr = ptr->next;
                }
                ptr->next = newNode;
            }
        }

        void count() {
            int counter = 0;
            Node *ptr = head;
            while (ptr->next != NULL) {
                ptr = ptr->next;
                counter++;
            }

            cout << counter;
        }
}

int main() {
    LinkedList list;
    list.count();
    list.add(2);
    list.count();
    return 0;
}
