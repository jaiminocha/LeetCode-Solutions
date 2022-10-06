class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    void coverIsland(vector<vector<char> > &grid, int n, int m, int x, int y, bool **visited){
        visited[x][y] = true;
        for (int i = 0; i < 4; i++){
            if (x + dx[i] >= 0 && y + dy[i] >= 0 && x + dx[i] < n && y + dy[i] < m && grid[x + dx[i]][y + dy[i]] == '1' && !visited[x + dx[i]][y + dy[i]]){
                coverIsland(grid, n, m, x + dx[i], y + dy[i], visited);
            }
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        bool **visited = new bool*[n];
        for (int i = 0; i < n; i++){
            visited[i] = new bool[m];
            for (int j = 0; j < m; j++){
                visited[i][j] = false;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (grid[i][j] == '1' && !visited[i][j]){
                    coverIsland(grid, n, m, i, j, visited);
                    ans++;
                }
            }
        }
        
        for (int i = 0; i < n; i++){
            delete [] visited[i];
        }
        delete [] visited;
        
        return ans;
    }
};