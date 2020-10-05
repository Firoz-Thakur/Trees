void travrsl(Node* node,map<int,int> &mp,int l)
{
 if(node==NULL)
  return;
     
  mp[l]=node->data;
  travrsl(node->left,mp,l+1);
  travrsl(node->right,mp,l+1);
    
}
void rightView(Node *root)
{
    map<int,int> m;
    travrsl(root,m,0);
    
    for(auto it=m.begin();it!=m.end();it++)
    {
        cout<<it->second<<" ";
    }
   
}
