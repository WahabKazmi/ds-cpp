#include <iostream>
using namespace std;

class Node {

	public:
      int data;
      Node *next;
      Node *prev;

      Node() {
          next = nullptr;
          prev = nullptr;
      }
};

class LinkedList {
	public:
    	Node *head;
        LinkedList() {
        	head = nullptr;
        };
    	void add(int d) {
        	Node *newNode = new Node;
            newNode->data = d;
        	if (head == nullptr) {
            	head = newNode;
                cout << "First value added " << d << endl;
            } else {
            	Node *ptr = head;
                int counter = 0;
                while (ptr->next != NULL) {
                	ptr = ptr->next;
                    counter++;
                }
                ptr->next = newNode;
                newNode->prev = ptr;
                
                cout << "added another one " << d << endl;
            }
        };
        
        void count () {
            int counter = 1;
            if (head == NULL) {
            	cout << "List is empty" << endl;
            } else {
        	  Node *ptr = head;
              while (ptr->next != NULL) {
                  ptr = ptr->next;
                  counter++;
              }
              cout << "Size is " << counter;
            }
        }
};

int main() {

	LinkedList list;
    list.count();
    list.add(2);
    list.add(3);
    list.count();

	return 0;
}