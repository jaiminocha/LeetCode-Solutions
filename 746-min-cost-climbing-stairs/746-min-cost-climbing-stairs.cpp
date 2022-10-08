class Solution {
    int solve(vector<int> &cost, int n, vector<int> &dp){
        if (n < 2) return cost[n];

        if (dp[n] != -1){
            return dp[n];
        }
        
        int oneStep = cost[n] + solve(cost, n - 1, dp);
        int twoStep = INT_MAX;
        if (n > 1) twoStep = cost[n] + solve(cost, n - 2, dp);
        
        return dp[n] = min(oneStep, twoStep);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if (n == 2) return min(cost[0], cost[1]);
        
        vector<int> dp(n + 1, -1);
        
        return min(solve(cost, n - 1, dp), solve(cost, n - 2, dp));
    }
};