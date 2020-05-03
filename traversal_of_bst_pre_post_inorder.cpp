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

int countnode(node* root)
{
	if(root==NULL)
	 return 0;
   
   int nodeleft=countnode(root->left);
   int noderight=countnode(root->right);
   
   return (1+nodeleft+noderight);
 
}

int sum_of_node_of_tree(node* root)
{
	if(root==NULL)
	 return 0;
 	
 int leftsum=sum_of_node_of_tree(root->left);
 int rightsum=sum_of_node_of_tree(root->right);
 
 return root->data+leftsum+rightsum;	
}

int height(node* root)
{
	if(root==NULL)
	 return 0;
    
   int h1= height(root->left);
   int h2=height(root->right);
    
   return 1+ max(h1,h2); 
}

class Pair
{
	public :
	int height;
	int diamter;
};


 
Pair diameter(node* root)
{
	Pair p;
	
	if(root==NULL)
	 {
	 p.height=0;
	 p.diamter=0;
	 return p;
	 }
	
	Pair left=diameter(root->left);
	Pair right=diameter(root->right);
	
    p.height=1+max(left.height,right.height);
    
    p.diamter=max(left.height+right.height,max(left.diamter,right.diamter));
    
    return p;
	
}
 
int sumreplacement(node* root)
{
	if(root==NULL)
	 return 0;
	 
	if(root->left==NULL && root->right==NULL)
	 return root->data;
	 
    int leftsum=sumreplacement(root->left);
    int rightsum=sumreplacement(root->right);
	
	int temp=root->data;
	
	root->data=leftsum+rightsum;
	
	return temp+root->data;
}

class Hpair{
	
    public:
	int height;
	bool balance;
};

Hpair checkbalance(node* root)
{
	Hpair p;
	if(root==NULL)
	   {
	   	  p.height=0;
	   	  p.balance=true;
	   	  return p;
	   }
	 
	Hpair left= checkbalance(root->left);
	Hpair right= checkbalance(root->right);
	 
	p.height=max(left.height,right.height)+1;
	
	if(abs(left.height-right.height)<=1 && left.balance && right.balance)
	     p.balance=true;
    else
        p.balance=false;
       
       
    return p;   
}

node* builtTreeFromArry(int ar[],int s,int e)
{
    if(s>e)
      return NULL;
	
	int mid=(s+e)/2;
	
	node* root=new node(ar[mid]);
	root->left = builtTreeFromArry(ar,s,mid-1);
	root->right = builtTreeFromArry(ar,mid+1,e);
	 
	return root; 

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
 
 cout<<endl;
 
 cout<<"count the number of node in the tree"<<endl;
 cout<<countnode(root);
 
 cout<<endl;
 cout<<"sum of node of the tree"<<endl;
 
 cout<<sum_of_node_of_tree(root);
 
  cout<<endl;
 cout<<"height of the tree"<<endl;

 cout<<height(root);

 cout<<endl;
 cout<<"diameter of the tree"<<endl;
 
 Pair x=diameter(root);
 cout<<x.diamter;
 cout<<endl;
 
 cout<<"height of the tree is"<<endl;

 cout<<x.height<<endl;
 
 //replacement of the node by the decendent sums
 cout<<"level order traversal of the tree"<<endl;
 levelOrdermodified(root);
 cout<<endl;
 
 sumreplacement(root);
 cout<<"level order traversal after replacement"<<endl;
 
 levelOrdermodified(root);
 
 cout<<endl;
 cout<<"is the tree balanced or not"<<endl;
 
 Hpair p=checkbalance(root);
 
 if(p.balance)
  cout<<"tree is balanced"<<endl;
 else
  cout<<"tree is not balanced"<<endl;
 
 
 cout<<"make the avl tree from the array"<<endl;
 
 int ar[]={1,2,3,4,5};
 
 int s=0;
 int e=4;
 
 node* root1=builtTreeFromArry(ar,s,e);

 levelOrdermodified(root1);  
 

 return 0;
}




5 4 2 -1 -1 1 -1 -1 2  -1 -1

	preorder
5 4 2 1 2 
postorder
2 1 4 2 5 
inorder
2 4 1 5 2 
level order
5 4 2 2 1 
level order with NULL value
5 
4 2 
2 1 

count the number of node in the tree
5
sum of node of the tree
14
height of the tree
3
diameter of the tree
3
height of the tree is
3
level order traversal of the tree
5 
4 2 
2 1 

level order traversal after replacement
9 
3 2 
2 1 

is the tree balanced or not
tree is balanced
make the avl tree from the array
3 
1 4 
2 5 
