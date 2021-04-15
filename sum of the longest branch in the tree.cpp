https://practice.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1#




struct xpair{
  
  int h;
  int sum;
};

xpair help(Node* root)
{
    xpair x;
    if(root==NULL)
     {
         x.sum=0;
         x.h=0;
         return x;
     }
   
   xpair left=help(root->left);
   xpair right=help(root->right);
   
   if(left.h==right.h)
   {
         x.sum=root->data+max(left.sum,right.sum);
        x.h=left.h+1;
   }
   else if(left.h > right.h)
   {
       x.h=left.h+1;
       x.sum=root->data+left.sum;
   }
   else
   {
       x.h=right.h+1;
       x.sum=root->data+right.sum;  
   }
    
  return x;
}

int sumOfLongRootToLeafPath(Node* root)
{
	// Code here
	
	xpair y=help(root);
	return y.sum;

}
