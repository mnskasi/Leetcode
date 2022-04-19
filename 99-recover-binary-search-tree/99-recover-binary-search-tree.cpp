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
    vector<pair<TreeNode*,TreeNode*>> err;
    TreeNode* prev;
    TreeNode* too_small = nullptr;
    TreeNode* too_large = nullptr;
    bool done = false;
    void isValid(TreeNode* root) 
    {
        if ( done ) return;
        if ( root == nullptr) return;   // true
        isValid(root->left);
        if ( prev != nullptr && root->val  <= prev->val)         // false
        {
            if (!too_large)
                too_large = prev;
            else
                done = true;
            
            too_small = root;
        }
        prev = root;
        isValid(root->right);
    }

    public:
    void recoverTree(TreeNode* root) 
    {
        prev = nullptr;
        isValid( root);
        swap(too_small->val,too_large->val);
    }
};