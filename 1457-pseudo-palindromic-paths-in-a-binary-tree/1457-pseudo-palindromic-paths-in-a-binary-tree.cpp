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
    void solve(TreeNode* root, vector<int> v, int &ans){
        if (!root) return;
        if (!root->left && !root->right) {
            v[root->val]++;
            bool once = true;
            int i = 1;
            for (; i <= 9; i++){
                //cout << v[i] << " ";
                if ((v[i] & 1) && once){
                    once = false;
                }
                else if ((v[i] & 1) == 0){
                    continue;
                }
                else break;
            }//cout << "\n";
            if (i == 10) ans++;
            return;
        }
        
        v[root->val]++;
        
        solve(root->left, v, ans);
        solve(root->right, v, ans);
        
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        if (!root) return 0;
        int ans = 0;
        vector<int> v(10, 0);
        solve(root, v, ans);
        return ans;
    }
};