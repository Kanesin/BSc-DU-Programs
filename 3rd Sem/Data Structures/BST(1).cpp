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
	private:
	BSTNode*root;
	int TN,LN;
	
	/*====================
	INSERT NODE
	====================*/
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
				else if (data==current->info)
				break;			
			}
			if(data<parent->info)
				parent->left=temp;
			else if(data>parent->info)
				parent->right=temp;
			
		}
	}
	
	/*====================
	SEARCH 
	====================*/	
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

	/*====================
	INORDER WRAPPER
	====================*/	
	void inorder()
	{
		cout<<endl;
		if(root!=NULL)						
			inorder(root);
		else
			throw "Tree empty\n";
	}
	
	/*====================
	INORDER RECURSION
	====================*/
	void inorder(BSTNode*p)
	{
		if(p->left!=NULL)
			inorder(p->left);
		if(p!=NULL)
			cout<<p->info<<"\t";
		if(p->right!=NULL)
			inorder(p->right);
	}
	
	/*====================
	INORDER ITERATION
	====================*/
	void inorder2()
	{
		if(root!=NULL)
		{
			stack<BSTNode*> S(1000);
			BSTNode*current=root;
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

	/*====================
	PREORDER WRAPPER
	====================*/
	void preorder()
	{
		cout<<endl;
		if(root!=NULL)						
			preorder(root);
		else
			throw "Tree empty\n";
	}
	
	/*====================
	PREORDER RECURSION
	====================*/
	void preorder(BSTNode*p)
	{
		if(p!=NULL)
			cout<<p->info<<"\t";
		if(p->left!=NULL)
			preorder(p->left);
		if(p->right!=NULL)
			preorder(p->right);
	}
	
	/*====================
	PREORDER ITERATION
	====================*/
	void preorder2()
	{
		if(root==NULL)
			throw "Tree empty\n";
		else
		{
			stack<BSTNode*> S(1000);
			BSTNode*temp;
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
	}
		
	/*====================
	POSTORDER WRAPPER
	====================*/
	void postorder()
	{
		cout<<endl;
		if(root!=NULL)						
			postorder(root);
		else
			throw "Tree empty\n";
	}	
	
	/*====================
	POSTORDER RECURSION
	====================*/
	void postorder(BSTNode*p)
	{
		if(p->left!=NULL)
			postorder(p->left);
		if(p->right!=NULL)
			postorder(p->right);
		if(p!=NULL)
			cout<<p->info<<"\t";
	}
	
	/*====================
	POSTORDER ITERATION
	====================*/
	void postorder2()
	{
		if(root!=NULL)
		{
			stack<BSTNode*> S(1000);
			BSTNode*current=root,*temp;
			do
			{
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
			}while(!S.isEmpty()||current!=NULL)	;
		}
		else
			throw "Tree empty\n";
	}

	/*====================
	LEVEL BY LEVEL 
	====================*/
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
		
	/*====================
	COUNT WRAPPER
	====================*/
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

	/*====================
	COUNT NODES
	====================*/	
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
	
	/*====================
	HEIGHT WRAPPER
	====================*/
	void height()
	{
		cout<<"\nMaximum Height= "<<height(root)<<endl;
	}
	
	/*====================
	HEIGHT 
	====================*/
	int height(BSTNode*p)
	{
		if(p==NULL)
			return -1;
		else
		{
			int lh=height(p->left);
			int rh=height(p->right);
			return max(lh,rh)+1;
		}
	}
	
	/*====================
	MIRROR WRAPPER
	====================*/
	void mirror()
	{
		if(root!=NULL)
		{
			mirror(root);
			cout<<"\nMirrored the tree\n";	
		}
		else
			throw "Tree empty\n";		
	}
	
	/*====================
	MIRROR TREE
	====================*/
	void mirror(BSTNode* p)
	{
		BSTNode*temp;
		temp=p->left;
		p->left=p->right;
		p->right=temp;
		if(p->left!=NULL)
			mirror(p->left);
		if(p->right!=NULL)
			mirror(p->right);
	}	
	/*====================
	DELETE BY MERGE
	====================*/
	void deleteByMerge(int data)
	{
		if(root!=NULL)
		{
			BSTNode *current=root,*parent=NULL;
			while(current!=NULL)
			{
				
				if(current->info==data)
					break;
				else if(current->info>data)
					{
						parent=current;
						current=current->left;	
					}
				else if(current->info<data)
					{
						parent=current;
						current=current->right;	
					}
			}
			if(current==NULL)
				cout<<"\nData not found\n";
			else
			{
				BSTNode *val;
				if(current->left==current->right)			val=NULL;
				else if(current->left==NULL)				val=current->right;
				else if(current->right==NULL)				val=current->left;
				else
				{					
					BSTNode*temp=current->left;
					while(temp->right!=NULL)
						temp=temp->right;
					if(parent==NULL)						val=current->left;									
					else									val=temp;	
					
					temp->right=current->right;					
				}				
				
				if(parent==NULL)						root=val;
				else if(parent->left==current)			parent->left=val;
				else if(parent->right==current)			parent->right=val;
				delete current;
			}
		}
		else
			throw "Tree empty\n";		
	}
	/*====================
	DELETE BY COPY
	====================*/
	void deleteByCopy(int data)
	{
		if(root!=NULL)
		{
			BSTNode *current=root,*parent=NULL;
			while(current!=NULL)
			{
				
				if(current->info==data)
					break;
				else if(current->info>data)
					{
						parent=current;
						current=current->left;	
					}
				else if(current->info<data)
					{
						parent=current;
						current=current->right;	
					}
			}
			if(current==NULL)
				cout<<"\nData not found\n";
			else
			{
				int flag=0;
				BSTNode *val;
				if(current->left==current->right)			val=NULL;
				else if(current->left==NULL)				val=current->right;
				else if(current->right==NULL)				val=current->left;
				else
				{	
					flag=1;				
					BSTNode*temp=current->left,*temp2=current;
					while(temp->right!=NULL)
					{
						temp2=temp;
						temp=temp->right;
					}											
					if(temp2->right==temp)
						temp2->right=NULL;					
					else if(temp2->left==temp)
						temp2->left=NULL;
					current->info=temp->info;;
					delete temp;	
				}				
				if(flag==0)
				{
					if(parent==NULL)						root=val;
					else if(parent->left==current)			parent->left=val;
					else if(parent->right==current)			parent->right=val;
					delete current;	
				}					
			}
		}
		else
			throw "Tree empty\n";		
	}

	/*====================
	COPY WRAPPER
	====================*/	
	void copy()
	{
		BST  NewTree;
		NewTree.root=copy(root);
		NewTree.inorder();
	}
	
	/*====================
	COPY
	====================*/
	BSTNode* copy(BSTNode* p)
	{
		if(p!=NULL)
		{
			BSTNode*temp=new BSTNode(p->info);
			temp->left=copy(p->left);
			temp->right=copy(p->right);		
			return 	temp;
		}	
		else
			return NULL;
	}
	
	
	/*====================
	MENU
	====================*/
	int menu()
	{
		cout<<"\n\nMENU\n";
		cout<<"1. Insertion\n";
		cout<<"2. Search\n";
		cout<<"3. In Order Traversal\n";
		cout<<"4. In Order Traversal Iterative\n";
		cout<<"5. Pre Order Traversal\n";
		cout<<"6. Pre Order Traversal Iterative\n";
		cout<<"7. Post Order Traversal\n";
		cout<<"8. Post Order Traversal Iterative\n";
		cout<<"9. Level by Level Traversal\n";
		cout<<"10. Count no. of Leaf, Non Leaf & Total nodes\n";
		cout<<"11. Height of tree\n";
		cout<<"12. Mirror of tree\n";
		cout<<"13. Delete by merging\n";
		cout<<"14. Delete by Copy\n";
		cout<<"15. Mirror tree\n";
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
	
	/*====================
	HOST PROGRAM
	====================*/
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
					case 13: cout<<"Enter data to Deleted\n";
							 cin>>data;
						     deleteByMerge(data);
					break;					
					case 14: cout<<"Enter data to Deleted\n";
							 cin>>data;
						     deleteByCopy(data);
					break;					
					case 15: copy();
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
