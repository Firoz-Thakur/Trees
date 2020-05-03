#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class node{
public :	
	int data;
	node* left;
	node* right;
	
  node(int data)
  {
  	this->data=data;
  	this->left=NULL;
  	this->right=NULL;
  }
};

node* builtbst()
{
	int data;
	cin>>data;
	if(data==-1)
	  return NULL;
	
	node* root=new node(data);
	root->left=builtbst();
	root->right=builtbst();
	return root;
}
void  preorder(node* root)
{
	
	if(root==NULL)
	 return;
	
	cout<<root->data<<" ";  
	preorder(root->left);
    preorder(root->right);
}

void inorder(node* root)
{
	
	if(root==NULL)
	 return;

	inorder(root->left);
    cout<<root->data<<" ";  
    inorder(root->right);
}




void  postorder(node* root)
{
	
	if(root==NULL)
	 return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";  
}


 void levelOrder(node * root) 
 {
  
   if(root==NULL)
      return;
     
   queue<node*> q;
   q.push(root);
   while(!q.empty())
   {
       node* curr=q.front();
       cout<<curr->data<<" ";
       if(curr->left!=NULL)
         q.push(curr->left);
       if(curr->right!=NULL)
          q.push(curr->right);
        q.pop();
   }
 }
 
void levelOrdermodified(node* root)
{
	queue<node*> q;
	q.push(root);
	q.push(NULL);
//	cout<<
    while(!q.empty())
    {
    	node* curr=q.front();
    	
    	if(curr==NULL)
    	{
    		cout<<endl;
    		q.pop();
    		if(q.empty())
    		 return;
    		else
    		 q.push(NULL);
    	}
       else
        {
        	cout<<curr->data<<" ";
            if(curr->left!=NULL)
             q.push(curr->left);
            if(curr->right!=NULL)
             q.push(curr->right);
            q.pop();
        }
    }
	
}

int main() {
	// your code goes here
 
  node* root=builtbst();
  
  cout<<"preorder"<<endl;
  preorder(root);
  cout<<endl;
  
  cout<<"postorder"<<endl;
  postorder(root);
  cout<<endl;
  
  cout<<"inorder"<<endl;
  inorder(root);
  cout<<endl;
  
 cout<<"level order"<<endl;
 levelOrder(root);
 
 cout<<endl;
 cout<<"level order with NULL value"<<endl;
 levelOrdermodified(root);
 
 
 return 0;
}



5 4 2 -1 -1 1 -1 -1 2  3 -1 -1 4 -1 -1

preorder
5 4 2 1 2 3 4 
postorder
2 1 4 3 4 2 5 
inorder
2 4 1 5 3 2 4 
level order
5 4 2 2 1 3 4 
level order with NULL value
5 
4 2 
2 1 3 4 


