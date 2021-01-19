void help( map<int,list<int> > &mp,Node* root,int d)
{
    if(root==NULL)
    {
        return;
    }
    mp[d].push_back(root->data);
    help(mp,root->left,d+1);
    help(mp,root->right,d);
 
}



vector<int> diagonal(Node *root)
{
   // your code here
   vector<int> v;
   map<int,list<int> > mp;
   help(mp,root,0);
   
   for(auto x : mp)
   {
       int y=x.first;
       for(auto nbr : mp[y])
       {
           v.push_back(nbr);
       }
   }
   return v;
   
}
