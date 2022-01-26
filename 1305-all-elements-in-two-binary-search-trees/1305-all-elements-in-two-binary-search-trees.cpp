/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> mergevector (vector<int> &data1,vector<int> &data2)
    {
        vector<int> res;
        int i=0,j=0;
        int n=data1.size();
        int m=data2.size();
        while(i <n && j<m)
        {
            if (data1[i]<=data2[j])
            {
                res.push_back(data1[i++]);
            }
            else
            {
                res.push_back(data2[j++]);
            }
        }
        while(i<n)
        {
            res.push_back(data1[i++]);
        }
        while(j<m)
        {
            res.push_back(data2[j++]);
        }
        return res;
    }
    void solve(TreeNode * root,vector<int> &data)
    {
        if (root==NULL)
        {
            return;
        }
        solve(root->left,data);
        data.push_back(root->val);
        solve(root->right,data);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) 
    {
        vector<int>data1;
        vector<int>data2;
        solve(root1,data1);
        solve(root2,data2);
        vector<int>res;
        res=mergevector(data1,data2);
        return res;
    }
};