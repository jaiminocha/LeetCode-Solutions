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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // horizontal difference, level, nodes
        map<int, map<int, multiset<int> > > nodes;
        queue<pair<TreeNode*, pair<int, int> > > q;
        if (!root) return {};
        q.push(make_pair(root, make_pair(0, 0)));
        while (!q.empty()){
            TreeNode* front = q.front().first;
            int hd = q.front().second.first;
            int level = q.front().second.second;
            q.pop();
            nodes[hd][level].insert(front->val);
            if (front->left) q.push(make_pair(front->left, make_pair(hd - 1, level + 1)));
            if (front->right) q.push(make_pair(front->right, make_pair(hd + 1, level + 1)));
        }
        vector<vector<int> > ans;
        auto it = nodes.begin();
        
        for (auto i : nodes){
            // cout << i.first << ": ";
            vector<int> temp;
            for (auto j : i.second){
                // cout << j.first << ", ";
                temp.insert(temp.end(), j.second.begin(), j.second.end());
            }//cout << endl;
            ans.push_back(temp);
        }
        return ans;
    }
};