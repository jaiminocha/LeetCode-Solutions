class Solution {
public:
    void dfs(list<int> *l, int node, int &count, unordered_map<int, bool> &m){
        if (m[node]) return;
        m[node] = true;
        count++;
        // cout << node << ", ";
        for (auto nbr : l[node]){
            if (!m[nbr]){
                dfs(l, nbr, count, m);
            }
        }
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        list<int> *l = new list<int>[n];
        int count = 0;
        int size = edges.size();
        for (int i = 0; i < size; i++){
            l[edges[i][0]].push_back(edges[i][1]);
            l[edges[i][1]].push_back(edges[i][0]);
        }
        unordered_map<int, bool> m;
        for (auto x : restricted){
            m[x] = true;
        }
        dfs(l, 0, count, m);
        return count;
    }
};