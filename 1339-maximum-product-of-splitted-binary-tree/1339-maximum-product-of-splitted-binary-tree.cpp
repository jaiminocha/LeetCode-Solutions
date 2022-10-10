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
const int mod = 1e9 + 7;
class Solution {
public:
    int totalSum(TreeNode* root){
        if (!root) return 0;
        
        return root->val + totalSum(root->left) + totalSum(root->right);
    }
    int solve(TreeNode* root, int &ts, long long int &maxProduct){
        if (!root) return 0;
        
        int l = solve(root->left, ts, maxProduct);
        int r = solve(root->right, ts, maxProduct);
        
        long long int sumSubTree = (root->val + l + r);
        maxProduct = max(((ts - sumSubTree) * sumSubTree), maxProduct);
        return sumSubTree;
    }
    int maxProduct(TreeNode* root) {
        int tsum = totalSum(root);
        long long int ans = INT_MIN;
        int x = solve(root, tsum, ans);
        ans = ans % mod;
        return (int)ans;
    }
};