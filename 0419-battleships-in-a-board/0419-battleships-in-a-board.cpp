int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
class Solution {
public:
    void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int n, int m, int i, int j){
        visited[i][j] = true;
        
        for (int k = 0; k < 4; k++){
            int x = dx[k] + i;
            int y = dy[k] + j;
            if (x >= 0 && y >= 0 && x < n && y < m && board[x][y] != '.' && !visited[x][y]){
                dfs(board, visited, n, m, x, y);
            }
        }
    }
    int countBattleships(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        
        vector<vector<bool>> visited(n, vector<bool> (m, false));
        int num = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (board[i][j] != '.' && !visited[i][j]){
                    dfs(board, visited, n, m, i, j);
                    num++;
                }
            }
        }
        return num;
    }
};