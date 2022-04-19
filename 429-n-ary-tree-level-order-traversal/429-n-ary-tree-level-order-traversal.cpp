/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector< vector<int> > res;
    void solve(Node * root, int ind)
    {
        if (root == NULL) return;
        if (ind == res.size())
        {
            vector<int> temp;
            res.push_back(temp);
        }
        res[ind].push_back(root->val);
        for (int i=0;i< root->children.size();i++)
        {
            solve(root->children[i],ind+1);
        }
    }
    vector<vector<int>> levelOrder(Node* root) 
    {
        solve(root,0);
        return res;
    }
};