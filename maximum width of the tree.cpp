Given a Binary Tree, find the maximum width of it. Maximum width is defined as the maximum number of nodes in any level.
For example, maximum width of following tree is 4 as there are 4 nodes at 3rd level.



approach :simple approach is using level order traversal.

int getMaxWidth(Node* root)
{
    
   // Your code here
  queue<Node*> q;
  q.push(root);
  q.push(NULL);
  int ans=0;
  int c=0;
  while(!q.empty())
  {
      Node* curr=q.front();
      if(curr==NULL)
      {
          q.pop();
          ans=max(c,ans);
          c=0;
          if(!q.empty())
          {
              q.push(NULL);
          }
      }
      else
      {
          if(curr->left!=NULL)
           q.push(curr->left);
          if(curr->right!=NULL)
           q.push(curr->right);
           q.pop();
           c++;
      }
  }


return ans;

}
