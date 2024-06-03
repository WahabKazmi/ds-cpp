#include <iostream>
using namespace std;

class Node {

	public:
      int data;
      Node *next;

      Node() {
          next = nullptr;
      }
};

class LinkedList {
	public:
    	Node *head;
        LinkedList() {
        	head = nullptr;
        };
    	void add(int d) {
        	
        	if (head == nullptr) {
                Node *newNode = new Node;
                newNode->data = d;
            	newNode->next = head;
            	head = newNode;
                head->next = head;
                cout << "First value added " << d << endl;
                
            } else {
                Node *newNode = new Node;
                newNode->data = d;
            	Node *ptr = head;
                while (ptr->next != head) {
                	ptr = ptr->next;
                }
            	newNode->next = head;
                ptr->next = newNode;
                
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