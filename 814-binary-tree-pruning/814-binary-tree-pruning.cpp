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
    TreeNode* removeSubtree(TreeNode* root){
        if (!root){
            return NULL;
        }
        root->left = removeSubtree(root->left);

        root->right = removeSubtree(root->right);
        if (root->val == 0 && root->right == NULL && root->left == NULL){
            return NULL;
        }
        return root;
    }
    TreeNode* pruneTree(TreeNode* root) {
        if (!root){
            return root;
        }
        root = removeSubtree(root);
        return root;
    }
};