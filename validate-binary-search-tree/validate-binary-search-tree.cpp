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
    int maxval(TreeNode* root){
        while(root->right!=NULL) root = root->right;
        return root->val;
    }
    int minval(TreeNode* root){
        while(root->left!=NULL) root = root->left;
        return root->val;
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return true;
        bool left = isValidBST(root->left),right = isValidBST(root->right);
        bool verdict = left && right;
        if(root->left!=NULL) verdict = verdict && maxval(root->left) < (root->val);
        if(root->right!=NULL) verdict = verdict && minval(root->right) > (root->val);
        return verdict;
    }  
};