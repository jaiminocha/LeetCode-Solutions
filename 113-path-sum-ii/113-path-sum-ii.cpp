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
    void solve(TreeNode* root, int target, vector<vector<int>> &ans, vector<int> output){
        if (!root) {
            return;
        }
        // if (target < 0) return;
        if (!root->left && !root->right){
            output.push_back(root->val);
            // long long int sum = accumulate(output.begin(), output.end(), 0);
            target -= root->val;
            if (0 == target) {
                ans.push_back(output);
            }
            output.pop_back();
            return;
        }
        output.push_back(root->val);
        solve(root->left, target - root->val, ans, output);
        solve(root->right, target - root->val, ans, output);
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> output;
        solve(root, targetSum, ans, output);
        return ans;
    }
};