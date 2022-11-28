class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int> > ans(2);
        int n = matches.size();
        map<int, pair<int, int> > m; // player, {wins, losses}
        
        for (int i = 0; i < n; i++){
            int w = matches[i][0], l = matches[i][1];
            int prev_losses = 0;
            if (m.count(l)) prev_losses = m[l].second;
            m[w] = {1, m[w].second};
            m[l] = {m[l].first, prev_losses + 1};
        }
        vector<int> w, l;
        for (auto x : m){
            if (x.second.second == 0){
                w.push_back(x.first);
            }
            else if (x.second.second == 1){
                l.push_back(x.first);
            }
        }
        ans[0] = w;
        ans[1] = l;
        return ans;
    }
};