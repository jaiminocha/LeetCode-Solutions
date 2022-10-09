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
    void inorder(TreeNode* root, vector<int> &nums){
        if (!root) return;
        
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        
        vector<int> nums;
        inorder(root, nums);
        
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++){
            int newTarget = k - nums[i];
            if (m.count(newTarget)) return true;
            m[nums[i]] = i;
        }
        return false;
    }
};