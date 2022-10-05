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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (!root) return root;
        if (depth == 1){
            TreeNode* newNode = new TreeNode(val);
            newNode->left = root;
            return newNode;
        }
        queue<TreeNode*> q;
        q.push(root);
        depth--;
        while (!q.empty()){
            int size = q.size();
            depth--;
            bool nextSet = (depth == 0);
            for (int i = 0; i < size; i++){
                TreeNode* front = q.front();
                q.pop();
                if (nextSet){
                    if (front->left){
                        TreeNode* newNode = new TreeNode(val);
                        newNode->left = front->left;
                        front->left = newNode;
                    }
                    else {
                        TreeNode* newNode = new TreeNode(val);
                        front->left = newNode;
                    }
                    if (front->right){
                        TreeNode* newNode = new TreeNode(val);
                        newNode->right = front->right;
                        front->right = newNode;
                    }
                    else {
                        TreeNode* newNode = new TreeNode(val);
                        front->right = newNode;
                    }
                }
                else {
                    if (front->left) {
                        q.push(front->left);
                    }
                    if (front->right) {
                        q.push(front->right);
                    }    
                }
                
            }
            //cout << depth << "\n";
            if (nextSet) break;
        }
        return root;
    }
};