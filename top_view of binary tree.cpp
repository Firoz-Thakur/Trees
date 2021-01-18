https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1


void topView(struct Node *root)
{
    //Your code here
    queue<pair<Node*,int>> q;
    map<int,int> mp;
    
    q.push(make_pair(root,0));
    
    while(!q.empty())
    {
        auto x=q.front();
        q.pop();
        
        if(mp.find(x.second)==mp.end())
        {
            mp[x.second]=(x.first)->data;
        }
        if((x.first)->left)
        {
            q.push(make_pair((x.first)->left,x.second-1));
        }
        if((x.first)->right)
        {
            q.push(make_pair((x.first)->right,x.second+1));
        }
    }
    
    for(auto it=mp.begin();it!=mp.end();it++)
    {
        cout<<it->second<<" ";
    }
}
