void help(Node* node,map<int,int> &mp,int d)
{
  if(node==NULL)
   return ;
 mp[d]=node->data;
 
 help(node->right,mp,d+1);
 help(node->left,mp,d+1);
 

}





void leftView(Node *root)
{
//max_depth=-1;
map<int,int> mp;
help(root,mp,0);

for(auto it=mp.begin();it!=mp.end();it++)
{
    cout<<it->second<<" ";
}
}
