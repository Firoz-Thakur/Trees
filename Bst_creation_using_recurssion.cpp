#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class node{
	 
	 public:
	 int data;
	 node* left;
	 node* right;
	 
	 node(int d)
	 {
	 	data=d;
	 	left=NULL;
	 	right=NULL;
	 }
};


node* insertNode(node* root,int data)
{
	if(root==NULL)
	  return new node(data);
	
	if(data<=root->data)
	  root->left=insertNode(root->left,data);
	else
	 root->right=insertNode(root->right,data);
	
 
 return root;	
}


node* builtBST()
{
	int data;
	cin>>data;
	
	node* root=NULL;
	while(data!=-1)
	{
	    root=insertNode(root,data);
		cin>>data;
	}
 	
  return root;	
}

void inorder(node* root)
{
	if(root==NULL)
	 return;
	 
	inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void levelorder(node* root)
{
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty())
	{
		node* cur=q.front();
		if(cur==NULL)
		{
			cout<<endl;
			q.pop();
			if(!q.empty())
			 q.push(NULL);
		}
		else
		{
			cout<<cur->data<<" ,";
			q.pop();
			if(cur->left!=NULL)
			 q.push(cur->left);
			if(cur->right!=NULL)
			 q.push(cur->right);
		}
	}

}

int main() {
	// your code goes here
	
	node* root=NULL;
	
	root=builtBST();
	
	cout<<"Level order traversal "<<endl;
	levelorder(root);
	
	cout<<endl;
    cout<<"Inorder traversal of BST"<<endl;

    inorder(root);
	return 0;
}
