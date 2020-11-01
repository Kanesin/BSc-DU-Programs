#include <iostream>
#include <conio.h>
using namespace std;

class SinglyLinkedList{

	class Node{
		public:
			int data;
			Node *next;
			Node(int d){
				data = d;
				next = NULL;
			}
	};
	
	Node *head, *tail;
	
public:
	
	Node* add(int data){
		Node *temp = new Node(data);
		if(head == NULL)
			head = tail = temp;
		else
			tail->next = temp;
		tail = temp;
		
		return temp;
	}
	
	Node* add(int pos, int data){
		if(head == NULL)
			add(data);
		else{
			Node *current= head, *next = head;
			Node *temp = new Node(data);
			for(int i=0;i<pos;i++){
				current = next;
				next= current->next;
				if (next==NULL){
					current->next = temp;
					tail = temp;
					return temp;
				}
			}
			temp->next = current->next;
			current->next = temp;
			tail = temp;
			return temp;
		}
	}
	
	void display(){
		Node *next = head;
		while(next->next != NULL){
			cout << next-> data << " ";
			next = next->next;
		}
	}
	
	
};

int main(){
	SinglyLinkedList *list;
	list = new SinglyLinkedList();
	list->add(5);
	list->add(6);
	list->add(7);
	list->add(8);
	list->add(3,96);
	list->add(7,96);
	list->display();
	
	getch();
	return 0;
}
