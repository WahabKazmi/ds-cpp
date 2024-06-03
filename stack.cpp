#include <iostream>
using namespace std;


class Stack {
	
    public:
      int values[10];
      int top = 0;

      void push(int val) {
            if (top == 10) {
              cout << "Stack is full";
            } else {
            	values[top] = val;
                top++;
                cout << "value added in stack " << val << endl;
            }
      }
      
      void pop() {
      	values[--top];
        cout << "deleted" << endl;
      }
      
      void size() {
      	cout << "Size is " << top << endl;
      }
	
};


int main() {
	Stack s;
    s.push(2);
    s.size();
    s.push(4);
    s.size();
    s.push(5);
    s.size();
    s.size();
	return 0;
}