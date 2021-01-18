https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1

vector <int> zigZagTraversal(Node* root)
{
	// Code here
	stack<Node*> s1;
	stack<Node*> s2;
//	vector<int> v;
	s1.push(root);
	vector<int> v;
	while(!s1.empty() || !s2.empty())
	{
	    while(!s1.empty())
	    {
	        auto x=s1.top();
	        s1.pop();
	        v.push_back(x->data);
	        if(x->left)
	         s2.push(x->left);
	        if(x->right)
	         s2.push(x->right);
	    }
	    
	    while(!s2.empty())
	    {
	        auto y=s2.top();
	        s2.pop();
	        v.push_back(y->data);
	        if(y->right)
	         s1.push(y->right);
	        if(y->left)
	         s1.push(y->left);
	    }
	    
	}
	
	return v;
	
	
}
