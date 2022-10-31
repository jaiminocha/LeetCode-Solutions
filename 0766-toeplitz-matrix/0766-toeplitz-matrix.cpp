class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        
        for (int r = n - 1; r >= 0; r--){
            int temp = matrix[r][0];
            for (int i = r, j = 0; i < n && j < m; i++, j++){
                if (temp != matrix[i][j]) return false;
            }
        }
        
        for (int s = 1; s < m; s++){
            int temp = matrix[0][s];
            for (int i = 0, j = s; i < n && j < m; i++, j++){
                if (temp != matrix[i][j]) return false;
            }
        }
        
        return true;
    }
};