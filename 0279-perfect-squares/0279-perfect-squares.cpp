class Solution {
public:
    int dp[10001];
    int helper(int n){
        if (n < 0) {
            return INT_MAX;
        }
        if (n <= 3){
            return n;
        }

        if (dp[n] != -1){
            return dp[n];
        }

        int ans = INT_MAX;
        
        for (int i = 1; i * i <= n; i++){
            ans = min(ans, helper(n - (i * i)) + 1);
        }
        return dp[n] = ans;
    }
    
    int numSquares(int n) {
        memset(dp, -1, sizeof(dp));
        return helper(n);
    }
};