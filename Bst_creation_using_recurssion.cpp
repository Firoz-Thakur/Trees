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
   
	return 0;
}

1 5 2 7 3 8 4 -1


Level order traversal 
1 ,
5 ,
2 ,7 ,
3 ,8 ,
4 ,

Inorder traversal of BST
1 2 3 4 5 7 8 
not present
check for bst
yes !! it is bst
