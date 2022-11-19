class Solution {
public:
    int solve(vector<vector<int> > &g, int n, int m, int r, int c1, int c2, vector<vector<vector<int> > > &dp){
        if (r == n){
            return 0;
        }
        if (dp[r][c1][c2] != -1){
            return dp[r][c1][c2];
        }
        int op1 = 0, op2 = 0, op3 = 0;
        int cherry = g[r][c1] + g[r][c2];
        if (c1 == c2) cherry -= g[r][c1];
        // down-left
        if (c1 - 1 >= 0){
            int op = 0;
            for (int c = c2 - 1; c <= c2 + 1; c++){
                if (c >= 0 && c < m){
                    op = max(op, cherry + solve(g, n, m, r + 1, c1 - 1, c, dp));
                }
            }
            op1 = max(op1, op);
        }
        // down
        int op = 0;
        for (int c = c2 - 1; c <= c2 + 1; c++){
            if (c >= 0 && c < m){
                op = max(op, cherry + solve(g, n, m, r + 1, c1, c, dp));
            }
        }
        op2 = max(op2, op);
        // down-right
        if (c1 + 1 < m){
            int op = 0;
            for (int c = c2 - 1; c <= c2 + 1; c++){
                if (c >= 0 && c < m){
                    op = max(op, cherry + solve(g, n, m, r + 1, c1 + 1, c, dp));
                }
            }
            op3 = max(op3, op);
        }
        return dp[r][c1][c2] = max({op1, op2, op3});
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int> > > dp(n + 1, vector<vector<int> > (m + 1, vector<int> (7001, -1)));
        return solve(grid, n, m, 0, 0, m - 1, dp);
    }
};