class DisjointSet{
    vector<int> rank, parent, size;
public:
    DisjointSet(int n){
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findUnion(int node){  // find parent
        if (node == parent[node]){
            return node;
        }
        return parent[node] = findUnion(parent[node]);
    }
    void unionByRank(int u, int v){
        int node1 = findUnion(u);
        int node2 = findUnion(v);
        if (node1 == node2) return ;
        if (rank[node1] < rank[node2]){
            parent[node1] = node2;
        }
        else if (rank[node1] > rank[node2]){
            parent[node2] = node1;
        }
        else {
            parent[node2] = node1;
            rank[node1]++;
        }
    }
    void unionBySize(int u, int v){
        int node1 = findUnion(u), node2 = findUnion(v);
        if (node1 == node2){
            return;
        }
        if (size[node1] < size[node2]){
            parent[node1] = node2;
            size[node2] += size[node1]; 
        }
        else {
            parent[node2] = node1;
            size[node1] += size[node2];
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int counter = 0;  // number of stones connected
        int maxRow, maxCol;
        for (int i = 0; i < n; i++){
            maxRow = max(maxRow, stones[i][0]);
            maxCol = max(maxCol, stones[i][1]);
        }
        DisjointSet ds(maxRow + maxCol + 1);
        unordered_map<int, int> uniq;
        for (auto x : stones){
            int nodeRow = x[0];
            int nodeCol = x[1] + maxRow + 1;
            ds.unionBySize(nodeRow, nodeCol);
            uniq[nodeRow] = 1;
            uniq[nodeCol] = 1;
        }
        
        for (auto x : uniq){
            if (ds.findUnion(x.first) == x.first){
                counter++;
            }
        }
            
        return n - counter;
    }
};