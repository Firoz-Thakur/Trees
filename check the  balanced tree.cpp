Given a binary tree, find if it is height balanced or not. 
A tree is height balanced if difference between heights of left and right subtrees is not more than one for all nodes of tree. 


class xpair
{
    public:
     int h;
     int flag;
};



xpair help(Node* root)
{
    xpair p;
    if(root==NULL)
    {
       p.h=0;
       p.flag=true;
       return p;
    }
    xpair p1=help(root->left);
    xpair p2=help(root->right);
    
    if(abs(p1.h-p2.h)<=1 &&  p1.flag && p2.flag)
    {
        p.flag=true;
    }
    else
    {
        p.flag=false;
    }
   p.h=max(p1.h,p2.h)+1;
   return p;
}



bool isBalanced(Node *root)
{
    //  Your Code here
    if(root==NULL) 
     return true;
   xpair x=help(root);
   return x.flag;
}
