class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        
        vector<int> ans;
        int n = mat.size();
        int m = mat[0].size();
        if (m == 1 || n == 1){
            for (auto x : mat) for (auto y : x) ans.push_back(y);
            return ans;
        }
        bool up = true;
        for (int i = 0; i < n; i++){
            vector<int> temp;
            for (int r = i, c = 0; r >= 0 && c < m; r--, c++){
                temp.push_back(mat[r][c]);
            }
            if (!up) reverse(begin(temp), end(temp));
            up = !up;
            for (auto x : temp) ans.push_back(x);
        }
        for(int j = 1; j < m; j++){
            vector<int> temp;
            for (int r = n - 1, c = j; c < m && r >= 0; r--, c++){
                temp.push_back(mat[r][c]);
            }
            if (!up) reverse(begin(temp), end(temp));
            up = !up;
            for (auto x : temp) ans.push_back(x);
        }
        
        return ans;
    }
};