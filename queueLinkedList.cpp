#include <iostream>
using namespace std;

class Node {
	public:
    	int data;
        Node *next;
};

class LinkedList {
	public:
    	Node *head = NULL;
        
        void add(int d) {
        	if (head == NULL) {
            	Node *newnode = new Node;
                newnode->data = d;
                newnode->next = NULL;
                head = newnode;
                cout << "First node added " << d << endl;
            } else {
            
            	Node *ptr = head;
                
            	while (ptr->next != NULL) {
                	ptr->next = ptr;
                };
                
                cout << "Found the last node value =>" << ptr->data << endl;
                Node *newnode = new Node;
                newnode->data = d;
                ptr->next = newnode;
                newnode->next = NULL;
                
                cout << "Node added at last " << d << endl;                
            }
        };
        
        void remove() {
        	if (head == NULL) {
            	cout << "List is empty" << endl;
            } else {
            	Node *ptr = head;
                while(ptr->next != NULL) {
                	ptr = ptr->next;
                };
                delete ptr;
                ptr->next = NULL;
            }
        };
        
        void size() {
        	if (head == NULL) {
            	cout << "Empty list" << endl;
            } else {
            	int counter = 1;
            	Node *ptr = head;
                while(ptr->next != NULL) {
                	ptr = ptr->next;
                    counter++;
                }
                cout << "size is " << counter << endl;
            }
        };
};

class Queue {
	public:
    	LinkedList list;
    	void enqueue(int d) {
        	list.add(d);
        }
        void dequeue() {
        	list.remove();
        };
        void size() {
        	list.size();
        };
};

int main() {
	Queue q;
    q.size();
    q.enqueue(2);
    q.enqueue(4);
    q.enqueue(6);
    q.enqueue(8);
    q.enqueue(10);
    q.size();
    
	return 0;
};