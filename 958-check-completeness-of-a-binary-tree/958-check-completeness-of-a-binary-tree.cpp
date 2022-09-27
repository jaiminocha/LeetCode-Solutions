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
    bool isCompleteTree(TreeNode* root) {
        if (!root) return true;
        queue<TreeNode*> q;
        q.push(root);
        bool canHave = true;
        while (!q.empty()){
            int size = q.size();
            
            for (int i = 0; i < size; i++){
                TreeNode* front = q.front();
                q.pop();
                
                if (front->left){
                    if (canHave){
                        q.push(front->left);
                    }
                    else return false;
                }
                else canHave = false;
                if (front->right){
                    if (canHave){
                        q.push(front->right);
                    }
                    else return false;
                }
                else canHave = false;
            }
        }
        return true;
    }
};