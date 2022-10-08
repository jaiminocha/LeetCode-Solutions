class Solution {
    int memo[101][101] = {0};
public:
    int uniquePaths(int m, int n) {
        
        if (m == 1 && n == 1){
            return 1;
        }
        if (m < 1 || n < 1){
            return 0;
        }
        
        if (memo[m][n] != 0){
            return memo[m][n];
        }
        
        return memo[m][n] = uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
    }
};