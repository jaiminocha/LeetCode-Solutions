class Solution {
public:
    bool canPlace(vector<vector<char>>& board, int i, int j, int n){
        // check row and column if same number already exists
        char c = board[i][j];
        board[i][j] = '.';
        for (int x = 0; x < n; x++){
            if (board[x][j] == c || board[i][x] == c) {
                board[i][j] = c;
                return false;
            }
        }
        // check if the sub-grid already has that number or not
        int sn = sqrt(n);
        int sx = (i / sn) * sn;
        int sy = (j / sn) * sn;
        for (int x = sx; x < sx + sn; x++){
            for (int y = sy; y < sy + sn; y++){
                if (board[x][y] == c){
                    board[i][j] = c;
                    return false;
                }
            }
        }
        board[i][j] = c;
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (board[i][j] != '.' && !canPlace(board, i, j, n)) return false;
            }
        }
        return true;
    }
};