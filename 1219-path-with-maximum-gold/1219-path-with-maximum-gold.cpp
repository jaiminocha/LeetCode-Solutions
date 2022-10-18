int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
class Solution {
public:
    int dfs(vector<vector<int> > &grid, int n, int m, int i, int j){
        if (i < 0 || j < 0 || i == n || j == m || grid[i][j] <= 0){
            return 0;
        }
        int val = grid[i][j];
        grid[i][j] = -val;
        int ans = val + max({dfs(grid, n, m, i + 1, j), dfs(grid, n, m, i, j + 1), dfs(grid, n, m, i - 1, j), dfs(grid, n, m, i, j - 1)});
    
        grid[i][j] = val;
        return ans;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        int ans = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (grid[i][j] != 0){
                    ans = max(ans, dfs(grid, n, m, i, j)); 
                    cout << ans << endl;
                }
            }
        }
        return ans;
    }
};