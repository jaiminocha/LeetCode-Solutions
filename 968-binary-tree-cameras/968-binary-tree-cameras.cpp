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
    void childParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &m){
        if (!root) return;
        if (!root->left && !root->right) return;
        queue<TreeNode*> pn;
        pn.push(root);
        m[root] = NULL;
        while (!pn.empty()){
            int size = pn.size();
            for (int i = 0; i < size; i++){
                TreeNode* front = pn.front();
                pn.pop();
                if (front->left){
                    m[front->left] = front;
                    pn.push(front->left);
                }
                if (front->right){
                    m[front->right] = front;
                    pn.push(front->right);
                }
            }
        }
    }
    
    void cameras(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &m, unordered_map<TreeNode*, bool> &monitored, int &ans){
        if (!root) return;
        cameras(root->left, m, monitored, ans);
        cameras(root->right, m, monitored, ans);
        
        if (monitored[root] != true && (root->left || root->right)){
            // if ( && (monitored[m[root]->left] || monitored[m[root]->right]))
            if (m[root]) monitored[m[root]] = true;
            monitored[root] = true;
            if (root->left) {
                monitored[root->left] = true;
            }
            if (root->right){
                monitored[root->right] = true;
            }
            // if (m[root]->left != NULL && monitored[m[root]->left] != true) monitored[m[root]->left] = true;
            // if (m[root]->right != NULL && monitored[m[root]->right] != true) monitored[m[root]->right] = true;
            ans++;
        }
        else if (monitored[root] == true && (root->left || root->right)){
            bool put = false;
            if (root->left && monitored[root->left] != true){
                monitored[root->left] = true;
                put = true;
            }
            if (root->right && monitored[root->right] != true){
                monitored[root->right] = true;
                put = true;
            }
            if (put) ans++;
        }
    }
public:
    // int minCameraCover(TreeNode* root) {
    //     /*
    //         ALGO: 
    //         1. Map the parents with the child nodes
    //         2. make a map (Node*, bool) which checks status, monitored or not
    //         3. bottom up, put camera on the parent of unmionitored node
    //     */
    //     if (!root->left && !root->right) return 1;
    //     int ans = 0;
    //     unordered_map<TreeNode*, TreeNode*> m;
    //     unordered_map<TreeNode*, bool> monitored;
    //     childParent(root, m);
    //     cameras(root, m, monitored, ans);
    //     return ans;
    // }
    
    int need(TreeNode* root, int &ans){
        if (!root) return 1;
        int left = need(root->left, ans);
        int right = need(root->right, ans);
        
        // parent gets camera as at least one child needs it
        if (left == -1 || right == -1){
            ans++;
            return 0;
        }
        
        // both children have a camera, parent doesn't need
        if (left == 0 || right == 0){
            return 1;
        }
        
        return -1;
    }
    
    
    void dfs(TreeNode* root, TreeNode* parent, int &ans, map<TreeNode*, bool> &m){
        if (!root) return;
        
        dfs(root->left, root, ans, m);
        dfs(root->right, root, ans, m);
        
        if ((parent == NULL && !m.count(root)) || !m.count(root->left) || !m.count(root->right)){
            ++ans;
            m[root] = true;
            m[root->left] = true;
            m[root->right] = true;
            m[parent] = true;
        }
    }
    int minCameraCover(TreeNode* root) {
        /*
            ALGO: 
            1. need a camera return -1
            2. have a camera return 0
            3. already covered by a camera return 1
        */
        // int ans = 0;
        // int y = need(root, ans);
        // if (y == -1) ans++;
        // return ans;
        
        
        // approach 2
        map<TreeNode*, bool> m;
        m[NULL] = true;
        int ans = 0;
        dfs(root, NULL, ans, m);
        return ans;
    }
};