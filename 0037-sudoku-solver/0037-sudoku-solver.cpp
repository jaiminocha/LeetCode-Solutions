class Solution {
public:
    bool canPlace(vector<vector<char>>& board, int i, int j, int n, int num){
        // check row and column if same number already exists
        char c = num + '0';
        for (int x = 0; x < n; x++){
            if (board[x][j] == c || board[i][x] == c) return false;
        }
        // check if the sub-grid already has that number or not
        int sn = sqrt(n);
        int sx = (i / sn) * sn;
        int sy = (j / sn) * sn;
        for (int x = sx; x < sx + sn; x++){
            for (int y = sy; y < sy + sn; y++){
                if (board[x][y] == c){
                    return false;
                }
            }
        }
        return true;
    }
    bool canSolve(vector<vector<char>>& board, int i, int j, int n){
        // all rows done
        if (i == n) return true;
        // all columns of current row done
        if (j == n){
            return canSolve(board, i + 1, 0, n);
        }
        // if there is a number already and not an emmpty space
        if (board[i][j] != '.') return canSolve(board, i, j + 1, n);
        // put numbers and check
        for (int num = 1; num <= n; num++){
            if (canPlace(board, i, j, n, num)){
                board[i][j] = (num + '0');
                // after placing the current check if further there is no problem
                bool couldBeSolved = canSolve(board, i, j + 1, n);
                if (couldBeSolved) {
                    return true;
                }
            }
        }
        // if no number can be placed in the current position, this sudoku is not valid
        board[i][j] = '.';
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        int n = board.size();
        bool x = canSolve(board, 0, 0, n);
    }
};