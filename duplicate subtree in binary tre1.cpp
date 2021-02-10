https://practice.geeksforgeeks.org/problems/duplicate-subtrees/1#

map<string,int> mp;
vector<int> v;
//int f=0;
string help(Node* root)
{
 string s="";    
  if(root==NULL)
    return "$";
  
  s=s+help(root->left);
  s=s+to_string(root->data);
  s=s+help(root->right);
   
  if(mp[s]==1){
   v.push_back(root->data);
  }
  //int x=stoi(s); 
  mp[s]++; 
  return to_string(root->data);
}        
void printAllDups(Node* root)
{
    // Code here
  mp.clear(); 
  v.clear();
  string s=help(root);
  sort(v.begin(),v.end());
  for(int i=0;i<v.size();i++)
  {
      cout<<v[i]<<" ";
  }
  if(v.size()==0)
  cout<<"-1";

}
