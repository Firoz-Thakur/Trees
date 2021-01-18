https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

vector <int> bottomView(Node *root)
{
   // Your Code Here
   queue<pair<Node*,int>>  q;
   map<int,int> mp;
   
   q.push(make_pair(root,0));
   
   while(!q.empty())
   {
       auto x=q.front();
       q.pop();
       Node* y=x.first;
       int d=x.second;
       mp[d]=y->data;
       
       if(y->left)
        q.push(make_pair(y->left,d-1));
       if(y->right)
        q.push(make_pair(y->right,d+1));
   }
   
  vector<int> v;
  for(auto it=mp.begin();it!=mp.end();it++)
  {
      v.push_back(it->second);
  }
    
return v;
   
}
