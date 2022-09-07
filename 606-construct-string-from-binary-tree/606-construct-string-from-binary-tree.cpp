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
    string helper1(TreeNode* root)
    {
        if (!root) return "";
        if (!root->left && !root->right){
            // char ch = (root->val + '0');
            string str = to_string(root->val);
            // str.push_back(ch);
            return (str);
        }
        if (!root->right){
            // char ch = (root->val + '0');
            string str = to_string(root->val);
            // str.push_back(ch);
            return  (str + "(" + helper1(root->left) + ")");
        }
        char ch = (root->val + '0');
        //cout <<endl << root->val << ch << endl;
        string str = to_string(root->val);
        return ((str + "(") + (helper1(root->left)) + ")(" + (helper1(root->right)) + ")");
    }
    string tree2str(TreeNode* root) {
        if (!root) return "";
        return helper1(root);
    }
};