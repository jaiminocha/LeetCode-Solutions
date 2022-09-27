class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        
        vector<int> left(n, -1), right(n, -1);
        int force = 0, idx = n - 1;
        for (int i = n - 1; i >= 0; i--){
            if (dominoes[i] == 'L'){
                force = -1;
                left[i] = i;
                idx = i;
            }
            else if(dominoes[i] == 'R') {
                force = 0;
            }
            else {
                if (force != 0){
                    left[i] = idx;
                }
            }
        }
        force = 0;
        for (int i = 0; i < n; i++){
            if (dominoes[i] == 'R'){
                force = 1;
                idx = i;
                right[i] = i;
            }
            else if(dominoes[i] == 'L') {
                force = 0;
            }
            else {
                if (force != 0){
                    right[i] = idx;
                }
            }
        }
        // for (auto x : left) cout << x << ", ";
        // cout << "\n";
        // for (auto x : right) cout << x << ", ";
        string ans = "";
        for (int i = 0; i < n; i++){
            if (left[i] == -1 && right[i] == -1){
                ans.push_back('.');
            }
            else if (right[i] == -1){
                ans.push_back('L');
            }
            else if (left[i] == -1){
                ans.push_back('R');
            }
            else if ((left[i] - i) < (i - right[i])){
                ans.push_back('L');
            }
            else if ((left[i] - i) > (i - right[i])){
                ans.push_back('R');
            }
            else {
                ans.push_back('.');
            }
            
        }
        return ans;
    }
};