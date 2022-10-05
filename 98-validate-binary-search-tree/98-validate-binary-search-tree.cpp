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
    bool solve(TreeNode* root, long minValue = LONG_MIN, long maxValue = LONG_MAX){
        if (!root) return true;
        if (root->val > minValue && root->val < maxValue && solve(root->left, minValue, root->val) && solve(root->right, root->val, maxValue)){
            return true;
        }
        return false;
    }
    
public:
    bool isValidBST(TreeNode* root) {
        return solve(root);
    }
};