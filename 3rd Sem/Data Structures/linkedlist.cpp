#include <iostream>
#include <conio.h>
using namespace std;
class Node
{
	public:
		int info;
		Node *next;
		
		Node(int data)
		{
			info=data;
			next=NULL;
			
				
		}
};

int main()
{
	Node *head, *tail;
	head = new Node(5);
	tail=head;
	Node *temp= new Node(10);
	head->next=temp;
	tail=temp;
	return 0;
	
}
