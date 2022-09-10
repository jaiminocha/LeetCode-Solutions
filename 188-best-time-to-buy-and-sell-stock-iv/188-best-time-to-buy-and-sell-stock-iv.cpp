class Solution {
public:
    int dp[10001][2][101];
    int solve(vector<int> &prices, int i, int buyAllowed, int count, int k){
        if (i == prices.size() || count == k){
            return 0;
        }
        if (dp[i][buyAllowed][count] != -1){
            return dp[i][buyAllowed][count];
        }
        int profit = 0;
        // buy
        if (buyAllowed && count <= k){
            int p1 = -prices[i] + solve(prices, i + 1, 0, count, k);
            int p2 = solve(prices, i + 1, 1, count, k);
            if (p1 > p2) {
                count++;
                profit = p1;
            }
            else profit = p2;
        } // sell
        else {
            profit = max(prices[i] + solve(prices, i + 1, 1, count + 1, k), solve(prices, i + 1, 0, count, k));
        }
        
        return dp[i][buyAllowed][count] = profit;
    }
    
    int maxProfit(int k, vector<int>& prices) {
        int counter = 0, n = prices.size();
        // vector<vector<int> > dp(n, vector<int> (2, -1));
        for (int i = 0; i <= 1000; i++){
            for (int j = 0; j < 2; j++){
                for (int k = 0; k < 101; k++){
                    dp[i][j][k] = -1;
                }
            }
        }
        return solve(prices, 0, 1, 0, k);
    }
};