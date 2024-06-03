#include <iostream>
using namespace std;


class Node {
	public:
    	int data = 0;
        Node *next = NULL;
};

class LinkedList {
	public:
    	Node *head = NULL;
        
        void add(int d) {
        	
            Node *newNode  = new Node;
            newNode->data = d;
            newNode->next = NULL;
            
            if(head == NULL) {
            	head = newNode;
            } else {
            	Node *ptr = head;
            	while (ptr->next != NULL) {
                	ptr = ptr->next;
                }
                ptr->next = newNode;
            }
            
			cout << "data has added ";
            cout << d;
            cout << endl;
        }
        
        void count(){
        	if (head == NULL) {
            	cout << "Empty list";
            	cout << endl;
            } else {
              int counter = 1;
              Node *ptr = head;
              while(ptr->next != NULL) {
                  counter++;
                  ptr = ptr->next;
              }
              cout << "Size is ";
              cout << counter;
              cout << endl;
            }
        }
        
        void search (int val) {
        	cout << "val is ";
        	cout << val;
        	cout << endl;
        	if (head == NULL) {
            	cout << "List is empty";
            } else {
            	
                int counter = 0;
                Node *ptr = head;
                while (ptr->next != NULL) {
                	ptr = ptr->next;
                    if (val == head->data) {
                    	counter++;
                    	cout << "Found the value ";
                    	cout << endl;
                    	break;
                    } else {
	                    counter++;
                    	cout << "Cannot find the value";
                        cout << val;
                        cout << ptr->data;
                    	cout << endl;
                    }
                }
                
            }
        }
        
};


int main() {
	
    LinkedList list;
    list.add(2);
    list.add(3);
    list.add(4);
    list.count();
    list.search(2);
	
	return 0;
}