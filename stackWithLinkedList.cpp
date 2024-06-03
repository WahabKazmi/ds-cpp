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
                cout << d << " added as first node" << endl;
            } else {
            	Node *newnode = new Node;
                newnode->data = d;
                newnode->next = head;
                head = newnode;
                cout << d << " added as another node" << endl;
            }
        };
        
        void remove() {
        	Node *temp = head;
            head = head->next;
            int removedData = temp->data;
            delete temp;
            cout << removedData << " deleted" << endl;
        };
        
        void size() {
        	int counter = 1;
            Node *ptr = head;
            while(ptr->next != NULL) {
            	ptr = ptr->next;
                counter++;
            }
            cout << "Size is " << counter << endl; 
        };
        
        void print() {
        	if(head == NULL) {
            	cout << "List is empty";
            }else {
            	Node *ptr = head;
                cout << "The printing has started" << endl;
            	while(ptr->next != NULL) {
                    cout << "=>" << ptr->data << endl;
                	ptr = ptr->next;
                };
                cout << "=>" << ptr->data << endl;
                cout << "The printing has ended" << endl;
            }
        };
};

class Stack {
	private:
    	LinkedList list;
	public:
    	void push(int d) {
        	list.add(d);
        }
        void pop() {
        	list.remove();
        }
        void count() {
        	list.size();
        };
        void print() {
        	list.print();
        };
};

int main() {
	Stack s;
    s.push(2);
    s.push(4);
    s.push(6);
    s.push(8);
    s.push(10);
    s.print();
    s.count();
    s.pop();
   	s.count();
    s.print();
    
	return 0;
}