#include <iostream>
using namespace std;

class Node
{
	int *left;
	int *right;
	int data;
}



Node* createbst(int ar[],int s,int e)
{
	if(s>e)
	 return NULL;
   
   int mid=s+e/2;
	
   Node *node=new Node(ar[mid]);
   node->left=createbst(ar,s,mid-1);
   node->right=createbst(ar,mid+1,e);
   return node;
}


int main() {
	// your code goes here
	int ar=[1,2,3,4,5];
	int n=5;
	Node* root=createbst(ar,0,n-1);
	
	return 0;
}
