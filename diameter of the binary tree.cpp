class xpair{
    public:
     int h;
     int d;
};
 
 xpair helper(Node* root)
 {
     xpair p;
     if(root==NULL)
     {
         p.h=0;
         p.d=0;
         return p;
     }
    xpair p1=helper(root->left);
    xpair p2=helper(root->right);

    p.h=max(p1.h,p2.h)+1;
    p.d=max((p1.h+p2.h),max(p1.d,p2.d));
    return p;
 }

int diameter(Node* node) {
    // Your code here
    
   xpair q=helper(node);
   return (q.d)+1;  // we are considering the edge only so we have to return 1 extra.
    
}
