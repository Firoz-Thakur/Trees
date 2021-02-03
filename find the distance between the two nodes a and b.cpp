https://practice.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1

Node* lca(Node* root,int a,int b)
{
    if(root==NULL)
     return NULL;
     
    if(root->data==a or root->data==b)
      return root;
     
    Node* left=lca(root->left,a,b);
    Node* right=lca(root->right,a,b);
    
    if(right!=NULL && left!=NULL)
    {
        return root;
    }
    if(left!=NULL)
     return left;
    return right;
}

int dis(Node* node,int a,int d)
{
  if(node==NULL)
   return -1;

  if(node->data==a)
  {
      return d;
  }
   int left=dis(node->left,a,d+1);
   int right=dis(node->right,a,d+1);
   
   return max(left,right);  // because we will not get the value (only -1 we will get)
   
}

int findDist(Node* root, int a, int b) {
    // Your code here
    
    Node* node=lca(root,a,b);
    int leftdis=dis(node,a,0);
    int rightdis=dis(node,b,0);
    
    return leftdis+rightdis;
}
