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
//     void solve(TreeNode* root, int minVal, int &ans){
//         if (!root) return;
//         if (root->val >= minVal){
//             minVal = root->val;
//             ans++;
//         }
        
//         solve(root->left, minVal, ans);
//         solve(root->right, minVal, ans);
//     }
//     int goodNodes(TreeNode* root) {
//         if (!root) return NULL;
        
//         int ans = 0;
//         int minVal = root->val;
//         solve(root, minVal, ans);
        
//         return ans;
        
//     }
    int helper(TreeNode* root, int minVal){
        return (root ? helper(root->left, max(minVal, root->val)) + helper(root->right, max(minVal, root->val)) + (root->val >= minVal) : 0);
    }
    int goodNodes(TreeNode* root) {
        if (!root) return NULL;
        
        return helper(root, -10001);
    }
};