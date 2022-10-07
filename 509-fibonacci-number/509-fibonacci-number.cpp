class Solution {
//     int solve(int n, vector<int> &dp){
//         if (n < 2) return n;
        
//         if (dp[n] != -1) return dp[n];
        
//         return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
//     }
public:
    int fib(int n) {
        // 1
        // if (n < 2) return n;
        // return fib(n-1) + fib(n-2);
        
        // 2
        // vector<int> dp(n + 1, -1);
        // return solve(n, dp);
        
        // 3
        int prev = 0, curr = 1, res = 0;
        for (int i = 2; i <= n; i++){
            res = prev + curr;
            prev = curr;
            curr = res;
        }
        if (n == 1) res = 1;
        return res;
    }
};