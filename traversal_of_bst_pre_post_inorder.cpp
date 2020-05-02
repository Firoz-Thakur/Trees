#include <iostream>
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
 void levelOrder(node * root) {
  
   if(root==NULL)
      return;
     
   queue<node* > q;
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

int main() {
	// your code goes here
 
  node* root=builtbst();
  preorder(root);
  cout<<endl;
  postorder(root);
  cout<<endl;
  inorder(root);
	
 cout<<"level order"<<endl;
 levelOrder(root);
	return 0;
}

5 4 2 -1 -1 1 -1 -1 2  3 -1 -1 4 -1 -1

5 4 2 1 2 3 4 
2 1 4 3 4 2 5 
2 4 1 5 3 2 4 


