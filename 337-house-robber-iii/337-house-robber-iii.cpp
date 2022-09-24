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
    
    int solve(TreeNode* root, bool canSteal, map<pair<TreeNode*, bool>, int> &dp){
        if (!root) return 0;
        
        if (dp.count({root, canSteal})){
            return dp[{root, canSteal}];
        }
        
        int op1 = 0;
        if (canSteal) {
            op1 = root->val + solve(root->left, !canSteal, dp) + solve(root->right, !canSteal, dp);
        }
        int op2 = solve(root->left, true, dp) + solve(root->right, true, dp);
        return dp[{root, canSteal}] = max(op1, op2);
    }
    int rob(TreeNode* root) {
        map<pair<TreeNode*, bool>, int> dp;
        return solve(root, true, dp);
    }
};