class Solution {
public:
    void solve(int n, int k, vector<int> &ans, int i, string output){
        if (output.size() == n){
            ans.push_back(stoi(output));
            return;
        }
        
        for (int j = 0; j <= 9; j++){
            if (j == 0 && output.size() == 0) continue;
            if (output.size() == 0){
                output.push_back(j + '0');
                solve(n, k, ans, i + 1, output);
                output.pop_back();
            }
            else {
                int diff = abs((output.back() - '0') - j);
                if (diff == k){
                    output.push_back(j + '0');
                    solve(n, k, ans, i + 1, output);
                    output.pop_back();
                }
            }
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        string output;
        solve(n, k, ans, 0, output);
        return ans;
    }
};