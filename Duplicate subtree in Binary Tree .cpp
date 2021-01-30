https://practice.geeksforgeeks.org/problems/duplicate-subtree-in-binary-tree/1




unordered_map<string ,int> mp;

string help(Node* root)
{
  if(root==NULL)
  {
     return "$";
  }
  string s="";
  if(root->left==NULL and  root->right==NULL)
  {
      s=to_string(root->data);
      return s;
  }
  s=s+to_string(root->data);
  s=s+help(root->left);
  s=s+help(root->right);
  mp[s]++;
  return s;
}



bool dupSub(Node *root)
{
     //your code here
     mp.clear();
  string s= help(root);
    
    for(auto x:mp)
    {
        if(x.second>=2)
        {
            return true;
        }
    }
    return false;
}
