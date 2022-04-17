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
    void Greater_Tree(TreeNode* root,int &res){
        // Base Condition
        if(root == NULL)
            return;
        
        // solve for greater element in right sub tree 
        Greater_Tree(root->right,res);
        
        // sum up val in result
        res += root->val;
        
        // update root->val
        root->val = res;
        
        // solve for greater value in left sub tree
        Greater_Tree(root->left,res);
    }
    
    TreeNode* convertBST(TreeNode* root) {
        int res = 0;
        
        Greater_Tree(root,res);
        
        return root;
        
    }
};