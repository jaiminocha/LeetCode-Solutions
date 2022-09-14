class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int> > ans;
        int n = points.size();
        
        priority_queue<pair<double, pair<int, int> > > pq;
        for (int i = 0; i < n; i++){
            int x = points[i][0];
            int y = points[i][1];
            double dis = sqrt((double)(x * x) + (y * y));
            // cout << dis << " ";
            if (pq.size() == k && pq.top().first > dis){
                pq.pop();
                pq.push({dis, {x, y}});
            }
            else if (pq.size() < k){
                pq.push({dis, {x, y}});
            }
        }
        while (!pq.empty()){
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            ans.push_back({x, y});
            pq.pop();
        }
        return ans;
    }
};