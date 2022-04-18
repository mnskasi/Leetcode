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
    int solve (TreeNode * root, int k, int & cnt)
    {
        if (root == NULL) return -1;
        int temp1 = solve(root->left,k,cnt);
        cnt++;
        if (cnt==k) return root->val;
        if (temp1 != -1) return temp1;
        int temp2 = solve(root->right,k,cnt);
        if (temp2 != -1 ) return temp2;
        return -1;
    }
    int kthSmallest(TreeNode* root, int k) {
        int cnt =0;
        return solve(root,k,cnt);
    }
};