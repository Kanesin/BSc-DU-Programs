#include<iostream> 
#include<conio.h>
#include<cstdlib>
#include "queue.cpp"
#include "stack-array.cpp"
using namespace std;
class BSTNode
{	
	public:
		int info;
		BSTNode *left;
		BSTNode *right;
		BSTNode(int data)
		{
			info=data;
			left=right=NULL;
		}
};
class BST
{
	BSTNode*root;
	int TN,LN;
	
	BST(const BST &ob)
	{
		root=ob.root;
	}	
	void insert(int data)
	{
		BSTNode*temp=new BSTNode(data);
		if(root==NULL)
			root=temp;
		else
		{
			BSTNode*current=root,*parent=NULL;
			while(current!=NULL)
			{
				parent=current;
				if(data<current->info)
					current=current->left;
				else if(data>current->info)
					current=current->right;				
			}
			if(data<parent->info)
				parent->left=temp;
			else if(data>parent->info)
				parent->right=temp;
		}
	}
	bool search(int data)
	{
		if(root==NULL)
			throw "Tree empty\n";
		else
		{	
			int f=0;
			BSTNode*current=root;
			while(current!=NULL)
			{
				if(data<current->info)
					current=current->left;
				else if(data>current->info)
					current=current->right;	
				else if (data==current->info)
					{
						f=1;
						break;
					}
			}
			return f;
		}
	}
	void inorder()
	{
		cout<<endl;
		if(root!=NULL)						
			inorder(root);
		else
			throw "Tree empty\n";
		cout<<endl;	
	}
	void inorder(BSTNode*p)
	{
		if(p->left!=NULL)
			inorder(p->left);
		if(p!=NULL)
			cout<<p->info<<"\t";
		if(p->right!=NULL)
			inorder(p->right);
	}
	void inorder2()
	{
		if(root!=NULL)
		{
			stack<BSTNode*> S(1000);
			BSTNode*current=root,*temp;
			do{
				while(current!=NULL)
				{
					S.push(current);
					current=current->left;
				}
				current=S.pop();
				cout<<current->info<<"\t";
				current=current->right;
			}while(!S.isEmpty()||current!=NULL);
		}
		else
			throw "Tree empty\n";	
	}
	void preorder()
	{
		cout<<endl;
		if(root!=NULL)						
			preorder(root);
		else
			throw "Tree empty\n";
		cout<<endl;	
	}
	void preorder(BSTNode*p)
	{
		if(p!=NULL)
			cout<<p->info<<"\t";
		if(p->left!=NULL)
			preorder(p->left);
		if(p->right!=NULL)
			preorder(p->right);
	}	
	void preorder2()
	{
		if(root!=NULL)
		{
			stack<BSTNode*> S(1000);
			BSTNode*current=root,*temp;
			S.push(root);
			while(!S.isEmpty())
			{
				temp=S.pop();
					cout<<temp->info<<"\t";
				if(temp->right!=NULL)
					S.push(temp->right);
				if(temp->left!=NULL)
					S.push(temp->left);
			}
				
		}
		else
			throw "Tree empty\n";
	}
	void postorder()
	{
		cout<<endl;
		if(root!=NULL)						
			postorder(root);
		else
			throw "Tree empty\n";
		cout<<endl;	
	}
	void postorder(BSTNode*p)
	{
		if(p->left!=NULL)
			postorder(p->left);
		if(p->right!=NULL)
			postorder(p->right);
		if(p!=NULL)
			cout<<p->info<<"\t";
	}
	void postorder2()
	{
		if(root!=NULL)
		{
			stack<BSTNode*> S(1000);
			BSTNode*current=root,*temp;
			do{
				while(current!=NULL)
				{
					S.push(current);
					if(current->right!=NULL)
						S.push(NULL);
					current=current->left;
				}
				temp=S.pop();
				if(temp!=NULL)
					cout<<temp->info<<"\t";
				else
				{
					temp=S.pop();
					current=temp->right;
					S.push(temp);
				}
			}while(!S.isEmpty()||current!=NULL);
		}
		else
			throw "Tree empty\n";
	}
	void breadthFirst()
	{
		if(root!=NULL)
		{
			cout<<endl;
			Queue <BSTNode*>q(2000);
			BSTNode *current=root;
			q.enqueue(current);		
			while(!q.isEmpty())
			{
				current=q.dequeue();
				cout<<current->info<<"\t";
				if(current->left!=NULL)
				q.enqueue(current->left);
				if(current->right!=NULL)
				q.enqueue(current->right);
			}
			cout<<endl;	
		}
		else
			throw "Tree empty\n";		
	}
	void height()
	{
		cout<<"\nHeight of Tree= "<<height(root);
		cout<<endl; 
	}
	int height(BSTNode* p)
	{
		if(p==NULL)
			return 0;		
		int lh=height(p->left);
		int rh=height(p->right);
		if(lh>rh)
			return lh+1;
		else
			return rh+1;
	}
	void count()
	{
		LN=TN=0;
		if(root!=NULL)
			count(root);
		cout<<"\nLeaf Nodes= "<<LN;
		cout<<"\nNon Leaf Nodes= "<<TN-LN;
		cout<<"\nTotal Nodes= "<<TN;
		cout<<endl;
	}
	void count(BSTNode*p)
	{
		if(p->left!=NULL)
			count(p->left);
		if(p!=NULL)
			TN++;
		if(p->right!=NULL)
			count(p->right);	
		if(p->left==NULL&&p->right==NULL)
			LN++;
	}
	
	void mirror()
	{
		if(root==NULL)
			throw "Tree empty\n";	
		else
		{
			mirror(root);
			cout<<"Tree has been reversed\n";	
		}
		
		
	}
	void mirror(BSTNode*p)
	{
		BSTNode*temp;
		if(p!=NULL)
		{
			temp=p->left;
			p->left=p->right;
			p->right=temp;
			if(p->left!=NULL)
			mirror(p->left);
			if(p->right!=NULL)
			mirror(p->right);	
		}		
	}
	int menu()
	{
		cout<<"\nMENU\n";
		cout<<"1. Insertion\n";
		cout<<"2. Search\n";
		cout<<"3. In Order Traversal\n";
		cout<<"4. In Order Traversal Iterative\n";
		cout<<"5. Pre Order Traversal\n";
		cout<<"6. Pre Order Traversal Iterative\n";
		cout<<"7. Post Order Traversal\n";
		cout<<"8. Post Order Traversal Iterative\n";
		cout<<"9. Level by Level Traversal\n";
		cout<<"10. Count Leaf, Non Leaf and Total Nodes\n";
		cout<<"11. Height of Tree\n";
		cout<<"12. Mirror tree\n";
		cout<<"Enter choice\n";
		int ch;
		cin>>ch;
		return ch;
	}
	public:
	BST()
	{
		root=NULL;
	}
	void prog()
	{
		int ch=0;
		int data;
		while(true)
		{
			try
			{		
				ch=menu();	
				switch(ch)
				{
					case 1:	cout<<"Enter data to insert\n";
							cin>>data;
							insert(data);
					break;
					case 2: cout<<"Enter data to search\n";
							cin>>data;
							if(search(data))
								cout<<"Data found";
							else
								cout<<"Data not found";
					break;
					case 3:	inorder();
					break;
					case 4:	inorder2();
					break;
					case 5:	preorder();
					break;					
					case 6:	preorder2();
					break;
					case 7:	postorder();
					break;
					case 8:	postorder2();
					break;					
					case 9:	breadthFirst();							
					break;
					case 10: count();
					break;
					case 11: height();
					break;	
					case 12: mirror();
					break;			
				}
			}	
			catch(const char*c)
			{
				cout<<c;
			}			
		}		
	}	
};
int main()
{
	BST b;
	b.prog();
	getch();
}
