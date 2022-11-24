class Solution {
public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    bool solve(vector<vector<char> > &b, int m, int n, int x, int y, string &w, int size, int i, vector<vector<bool> > &visited){
        if (i == size) {
            return true;
        }
        visited[x][y] = true;
        for (int d = 0; d < 4; d++){
            int x1 = x + dx[d], y1 = y + dy[d];
            if (x1 >= 0 && x1 < m && y1 >= 0 && y1 < n && b[x1][y1] == w[i] && !visited[x1][y1]){
                if (solve(b, m, n, x1, y1, w, size, i + 1, visited)){
                    return true;   
                }
            }
        }
        visited[x][y] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        int size = word.size();
        
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (word[0] == board[i][j]){
                    vector<vector<bool> > visited(m, vector<bool> (n, false));
                    if (solve(board, m, n, i, j, word, size, 1, visited)) return true;
                }
            }
        }
        return false;
    }
};