int daysleft[3] = {1, 7, 30};
class Solution {
public:
    int pass(vector<int> &days, int currDay, int dayPass, int i){
        int j = currDay + dayPass - 1;
        // cout << "day: " << j << endl;
        while (days[i] <= j){
            // cout << days[i] << " ";
            i++;
            if (i == days.size()) break;
        }//cout << endl;
        return i;
    }
    int solve(vector<int>& days, vector<int>& costs, int i, vector<int> &dp){
        if (i == days.size()){
            return 0;
        }
        
        if (dp[i] != INT_MAX) return dp[i];
        int res = INT_MAX;
        
        for (int j = 0; j < 3; j++){
            int idx = pass(days, days[i], daysleft[j], i);
            res = min(res, costs[j] + solve(days, costs, idx, dp));
        }
        
        return dp[i] = res;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size() + 1, INT_MAX);
        return solve(days, costs, 0, dp);
    }
};