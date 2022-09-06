class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        
        vector<int> dist1(n, -1), dist2(n, -1);
        dist1[node1] = dist2[node2] = 0;
        
        int node = node1, dist = 0;
        while (true){
            dist1[node] = dist++;
            node = edges[node];
            if (node == -1 || dist1[node] != -1) break;
        }
        node = node2;
        dist = 0;
        while (true){
            dist2[node] = dist++;
            node = edges[node];
            if (node == -1 || dist2[node] != -1) break;
        }
        int ans = -1, minDist = INT_MAX;
        for (int i = 0; i < n; i++){
            if (dist1[i] == -1 || dist2[i] == -1) continue;
            if (minDist > max(dist1[i], dist2[i])){
                minDist = max(dist1[i], dist2[i]);
                ans = i;
            }
        }
        return ans;
    }
};