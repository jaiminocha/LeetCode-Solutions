/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    // vector<vector<int>> levelOrder(Node* root) {
    //     vector<vector<int>> ans;
    //     queue<Node*> pendingNodes;
    //     if (!root) return ans;
    //     vector<int> v;
    //     v.push_back(root->val);
    //     ans.push_back(v);
    //     pendingNodes.push(root);
    //     while(!pendingNodes.empty()){
    //         Node* front = pendingNodes.front();
    //         pendingNodes.pop();
    //         vector<int> temp;
    //         for (int i = 0; i < front->children.size(); i++){
    //             temp.push_back(front->children[i]->val);
    //             pendingNodes.push(front->children[i]);
    //         }
    //         if (!temp.empty()) ans.push_back(temp);
    //     }
    //     return ans;
    // }
    
    
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        queue<Node*> pendingNodes;
        if (!root) return ans;
        vector<int> v;
        v.push_back(root->val);
        ans.push_back(v);
        pendingNodes.push(root);
        while(!pendingNodes.empty()){
            vector<int> temp;
            queue<Node*> pn(pendingNodes);
            while (!pendingNodes.empty()){
                pendingNodes.pop();
            }
            while (!pn.empty()){
                Node* front = pn.front();
                pn.pop();
                for (int i = 0; i < front->children.size(); i++){
                    temp.push_back(front->children[i]->val);
                    pendingNodes.push(front->children[i]);
                }
            }
            
            if (!temp.empty()) ans.push_back(temp);
        }
        return ans;
    }
};