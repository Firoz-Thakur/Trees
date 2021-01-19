https://practice.geeksforgeeks.org/problems/transform-to-sum-tree/1#

int help(Node* node)
{
   
    if(node==NULL)
     return 0;
     
    int x=node->data; 
    if(node->left==NULL && node->right==NULL)
     {
         node->data=0;
         return x;
     }
    int y=help(node->left);
    int z=help(node->right);
    
    node->data=y+z;
    return x+y+z;
}


void toSumTree(Node *node)
{
    // Your code here
    int x=help(node);
    
}
