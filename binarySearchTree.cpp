#include<iostream>
#include<conio.h>
using namespace std;
int count=0;
class Node
{
	public:
		Node* Left;
		int Data;
		Node* Right; 
};
class BST
{
	public:
		Node* Root;

		BST()
		{
			Root = NULL;	
		}

		void Insert(int value)
		{
			Node* newNode = new Node;
			newNode -> Data = value;
			newNode -> Left = NULL;
			newNode -> Right = NULL;
			if(Root == NULL)
			{
				Root = newNode;
				cout << "\n*** New Root Node Inserted ***";
			}
			else
			{
				Node* pre = NULL;
				Node* ptr = Root;
				while(ptr != NULL)
				{
					if(value < ptr -> Data)
					{
						pre = ptr;
						ptr = ptr -> Left;
						if(ptr == NULL)
						{
							pre -> Left = newNode;
							cout << "\n*** New Node Inserted Left Side ***";
						}
					}
					else if(value > ptr -> Data)
					{
						pre = ptr;
						ptr = ptr -> Right;
						if(ptr == NULL)
						{
							pre -> Right = newNode;
							cout << "\n*** New Node Inserted Right Side ***";
						}
					}
					else
					{
						delete newNode;
						cout << "\n*** Duplicate Value Found & Removed ***";
						count--;
						break;
					}
				}
			}
			count++;
		}
		
		void Search(int value)
		{
			if(Root == NULL)
			{
				cout << "\n\n*** Tree is Empty ***";
			}
			else
			{
				Node* ptr = Root;
				int found=0;
				while(ptr != NULL)
				{
					if(value == ptr -> Data)
					{
						cout << "\n\n*** Value is Found ***";
						found++;
						break;
					}
					else if(value < ptr -> Data)
					{
						ptr = ptr -> Left;
					}
					else
					{
						ptr = ptr -> Right;
					}
				}
				if(found == 0)
				{
					cout << "\n\n*** Value is Not Found ***";
				}	
			}
		}
		
		void Update(int value)
		{
			if(Root == NULL)
			{
				cout << "\n\n*** Tree is Empty ***";
			}
			else
			{
				Node* ptr = Root;
				int found=0;
				while(ptr != NULL)
				{
					if(value == ptr -> Data)
					{
						cout << "\n\nEnter New Updated Value -> ";
						cin >> value;
						ptr -> Data = value;
						cout << "\n\n*** Node Value Updated Successfully ***";
						found++;
						break;
					}
					else if(value < ptr -> Data)
					{
						ptr = ptr -> Left;
					}
					else
					{
						ptr = ptr -> Right;
					}
				}
				if(found == 0)
				{
					cout << "\n\n*** Value is Not Found ***";
				}
			}
		}
		
		void CountNodes()
		{
			cout << "\n\nTotal Nodes -> " << count;
		}
		
		void InOrder(Node* ptr)
		{
			if(ptr != NULL)
			{
				InOrder(ptr -> Left);
				cout << ptr -> Data << "  ";
				InOrder(ptr -> Right);
			}
		}
		
		void PreOrder(Node* ptr)
		{
			if(ptr != NULL)
			{
				cout << ptr -> Data << "  ";
				PreOrder(ptr -> Left);
				PreOrder(ptr -> Right);
			}
		}
		
		void PostOrder(Node* ptr)
		{
			if(ptr != NULL)
			{
				PostOrder(ptr -> Left);
				PostOrder(ptr -> Right);
				cout << ptr -> Data << "  ";
			}
		}
		
		Node* findMin(Node* ptr) 
		{
		    while(ptr -> Left != NULL) 
			{
		        ptr = ptr -> Left;
		    }
		    return ptr;
		}
		
		Node* deleteNode(Node* ptr, int key) 
		{
		    if(ptr == NULL) 
			{
		        return ptr;
		    }
		    if(key < ptr -> Data) 
			{
		        ptr -> Left = deleteNode( ptr -> Left, key);
		    }
		    else if(key > ptr -> Data) 
			{
		        ptr -> Right = deleteNode(ptr -> Right, key);
		    }
		    else 
			{
		        if(ptr -> Left == NULL) 
				{
		            Node* temp = ptr -> Right;
		            delete ptr;
		            count--;
		            return temp;
		        } 
				else if(ptr -> Right == NULL) 
				{
		            Node* temp = ptr -> Left;
		            delete ptr;
		            count--;
		            return temp;
		        }
		        Node* temp = findMin(ptr -> Right);
		        ptr -> Data = temp -> Data;
		        ptr -> Right = deleteNode(ptr -> Right, temp -> Data);
		    }
		    return ptr;
		}
};
main()
{
	BST Tree;
	while(1)
	{
		system("cls");
		int choice,value;
		cout << "***** BST Data Structure *****";
		cout << "\n\n1. Insert Record";
		cout << "\n\n2. Search Record";
		cout << "\n\n3. Update Record";
		cout << "\n\n4. Count Nodes";
		cout << "\n\n5. Inorder Traversal";
		cout << "\n\n6. Preorder Traversal";
		cout << "\n\n7. Postorder Traversal";
		cout << "\n\n8. Delete Record";
		cout << "\n\n9. Exit";
		cout << "\n\nEnter Your Choice -> ";
		cin >> choice;
		switch(choice)
		{
			case 1:
				cout << "\n\nEnter Node Value -> ";
				cin >> value;
				Tree.Insert(value);
				break;
			case 2:
				cout << "\n\nEnter Search Node Value -> ";
				cin >> value;
				Tree.Search(value);
				break;
			case 3:
				cout << "\n\nEnter Update Node Value -> ";
				cin >> value;
				Tree.Update(value);
				break;
			case 4:
				Tree.CountNodes();
				break;
			case 5:
				cout << "\n\nIn Order Traversal -> ";
				Tree.InOrder(Tree.Root);
				break;
			case 6:
				cout << "\n\nPre Order Traversal -> ";
				Tree.PreOrder(Tree.Root);
				break;
			case 7:
				cout << "\n\nPost Order Traversal -> ";
				Tree.PostOrder(Tree.Root);
				break;
			case 8:
				cout << "\n\nEnter Delete Node Value -> ";
				cin >> value;
				Tree.Root = Tree.deleteNode(Tree.Root, value);
				break;
			case 9:
				exit(0);
			default:
				cout << "\n\n*** Invalid Choice Please Try Again ***";
		}
		getch();
	}
}