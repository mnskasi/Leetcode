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
    void solve (TreeNode * root, TreeNode * &curr, TreeNode * &last)
    {
        if (root==NULL) return;
        solve(root->left,curr,last);
        if (curr == NULL)
        {
            curr = new TreeNode (root->val);
            last = curr;
        }
        else
        {
            last -> right = new TreeNode (root->val);
            last = last -> right;
        }
        solve(root->right,curr,last);
    }
    TreeNode* increasingBST(TreeNode* root) 
    {
        TreeNode * curr = NULL;
        TreeNode * last = NULL;
        solve(root,curr, last);
        return curr;
    }
};