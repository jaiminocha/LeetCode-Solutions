class Solution {
public:
    int solve(vector<int> &coins, int target, int n, int i, vector<vector<int> > &dp){
        if (i == n){
            if (target == 0){
                return 1;
            }
            return 0;
        }
        
        if (dp[i][target] != -1){
            return dp[i][target];
        }
        
        int way1 = solve(coins, target, n, i + 1, dp);
        int way2 = 0;
        if (target - coins[i] >= 0) way2 = solve(coins, target - coins[i], n, i, dp);
        
        return dp[i][target] = way1 + way2;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int> > dp(n, vector<int> (amount + 1, -1));
        return solve(coins, amount, n, 0, dp);
    }
};