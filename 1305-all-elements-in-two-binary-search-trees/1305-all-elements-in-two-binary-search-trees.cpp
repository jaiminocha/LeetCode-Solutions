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
    vector<int> t1;
    vector<int> t2;
public:
    void inorder(TreeNode* root, vector<int> &t){
        if (!root){
            return;
        }
        inorder(root->left, t);
        t.push_back(root->val);
        inorder(root->right, t);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        inorder(root1, t1);
        inorder(root2, t2);
        for (int i = 0; i < t2.size(); i++){
            t1.push_back(t2[i]);
        }
        sort(begin(t1), end(t1));
        return t1;
    }
};