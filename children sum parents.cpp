Given a binary tree, complete the function that returns true if the tree satisfies the following property:
For every node, data value must be equal to the sum of data values in left and right children. Consider data value as 0 for NULL child. 
Also, leaves are considered to follow the property.


int isSumProperty(Node *node)
{
 // Add your code here
  int x=0;
  int y=0;
  if(node==NULL || (node->left==NULL && node->right==NULL))
   return 1;
  
   
   
   if(node->left!=NULL)
     x=node->left->data;

   if(node->right!=NULL)
    y=node->right->data;
   
   return node->data==(x+y) && isSumProperty(node->left) && isSumProperty(node->right);
}
