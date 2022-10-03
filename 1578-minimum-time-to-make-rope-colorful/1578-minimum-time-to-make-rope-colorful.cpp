class Solution {
public:
    int solve(string &colors, vector<int> &nt, int n, int i, vector<int> &dp){
        if (i == n){
            return 0;
        }
        
        if (dp[i] != -1){
            return dp[i];
        }
        
        int time1 = 0;
        
        if (i < n - 1){
            int time = 0;
            if (colors[i] == colors[i + 1]){
                int j = i, maxVal = nt[i], sum = nt[i];
                while (j < n - 1 && colors[j] == colors[j + 1]){
                    maxVal = max(nt[j + 1], maxVal);
                    sum += nt[j + 1];
                    j++;
                }   
                time1 = sum - maxVal + solve(colors, nt, n, j + 1, dp);
            }
            else time1 = solve(colors, nt, n, i + 1, dp);
        }
        return dp[i] = time1;
    }
    int minCost(string colors, vector<int>& neededTime) {
        vector<int> dp(colors.size(), -1);
        return solve(colors, neededTime, colors.size(), 0, dp);
    }
};