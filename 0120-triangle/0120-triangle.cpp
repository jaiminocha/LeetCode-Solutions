class Solution {
public:
    int solve(vector<vector<int>>& triangle, int r, int c, vector<vector<int> > &dp){
        if (r == triangle.size()){
            return 0;
        }
        if (dp[r][c] != -1) return dp[r][c];
        int op1 = triangle[r][c] + solve(triangle, r + 1, c, dp);
        int op2 = triangle[r][c] + solve(triangle, r + 1, c + 1, dp);
        
        return dp[r][c] = min(op1, op2);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int> > dp(n, vector<int> (n, -1));
        return solve(triangle, 0, 0, dp);
    }
};