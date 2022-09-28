int dx[2] = {1, 0};
int dy[2] = {0, 1};
class Solution {
public:
    int dfs(vector<vector<int> > &grid, int n, int m, int i, int j, vector<vector<int> > &dp){
        if (i == n - 1 && j == m - 1){
            return grid[i][j];
        }
        
        if (dp[i][j] != -1){
            return dp[i][j];
        }
        
        int minS = INT_MAX;
        for (int k = 0; k < 2; k++){
            int x = i + dx[k], y = j + dy[k];
            if (x < n && y < m){
                minS = min(minS, dfs(grid, n, m, x, y, dp) + grid[i][j]);
            }
        }
        return dp[i][j] = minS;
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int> > dp(n, vector<int> (m, -1));
        return dfs(grid, n, m, 0, 0, dp);
    }
};