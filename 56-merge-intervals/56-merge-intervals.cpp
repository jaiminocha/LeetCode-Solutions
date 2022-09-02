class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        ans.push_back({intervals[0][0], intervals[0][1]});
        for (int i = 1; i < intervals.size(); i++){
            int size = ans.size();
            int st = ans[size - 1][0];
            int en = ans[size - 1][1];
            int ist = intervals[i][0];
            int ien = intervals[i][1];
            if (ist <= en){
                ans.pop_back();
                ans.push_back({st, max(en, ien)});
            }
            else {
                ans.push_back({intervals[i]});
            }
        }
        return ans;
    }
};