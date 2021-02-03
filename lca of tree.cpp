https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1#



Node* lca(Node* root ,int n1 ,int n2 )
{
   //Your code here
   if(root==NULL)
    return NULL;
    
  if(root->data==n1 or root->data==n2)
  {
      return root;
  }
  
  Node* left=lca(root->left,n1,n2);
  Node* right=lca(root->right,n1,n2);
  
  if(left!=NULL && right!=NULL)
   return root;
  
  if(left!=NULL)
   return left;
  
  return right;
}
