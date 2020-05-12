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

bool check_for_bst(node* root, int min=INT_MIN,int max=INT_MAX)
{
   if(root==NULL)
    return true;
   
   if(root->data>=min && root->data<=max && check_for_bst(root->left,min,root->data) &&  check_for_bst(root->right,root->data,max))
   {
   	 return true;
   }
  else
  {
   return false;
  }
  	
 }

bool search_element_in_bst(node* root,int data)
{
	
	if(root==NULL)
	 return false;
	 
    if(root->data==data)
     return true;
     
    if(root->data < data)
      return search_element_in_bst(root->right,data);
    else
     return search_element_in_bst(root->left,data);

}

node* deleteINBst(node* root,int data)
{
	if(root==NULL)
	 return root;
	
	else if(data<root->data)
	{
		root->left=deleteINBst(root->left,data);
		return root;
	}
   else if(data==root->data)
   {
   	 //found the node to be delete.
   	 // 1. node with zero child;
   	 
   	 if(root->left==NULL && root->right==NULL)
   	   {
   	   	delete root;
   	   	return NULL;
		}
	//2. only one child
	
	 if(root->left!=NULL && root->right==NULL)
	 {
	    node* temp=root->left;
	    delete root;
	    return temp;
	 }
	  if(root->left==NULL && root->right!=NULL)
	 {
		node* temp=root->right;
		delete root;
		return temp;
     }
     //3. when twwo child;
     
      node* replace =root->right;
      while(replace->left!=NULL)
      {
      	replace =replace ->left;
	  }
	  root->data=replace->data;
	  
	  root->right=deleteINBst(root->right,data);
	   return root;
     }
     
   else{   
    root->right=deleteINBst(root->right,data);
    return root;
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
  
    cout<<endl;
    
    if(search_element_in_bst(root,21))
     cout<<"present"<<endl;
    else
     cout<<"not present"<<endl;
    
   cout<<"check for bst"<<endl;
   
   if(check_for_bst(root))
    cout<<"yes !! it is bst";
   else
    cout<<"NO it is not bst";
    
    cout<<endl;
    
   deleteINBst(root,5); 
   
   cout<<endl;
   	levelorder(root);
   
	return 0;
}

input :
5 3 7 1 6 8 -1


Level order traversal 
5 ,
3 ,7 ,
1 ,6 ,8 ,

Inorder traversal of BST
1 3 5 6 7 8 
not present
check for bst
yes !! it is bst

6 ,
3 ,7 ,
1 ,6 ,8 ,
