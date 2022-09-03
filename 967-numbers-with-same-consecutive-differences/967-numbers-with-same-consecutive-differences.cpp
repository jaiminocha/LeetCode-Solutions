class Solution {
public:
    void solve(int n, int k, vector<int> &ans, string output){
        if (output.size() == n){
            ans.push_back(stoi(output));
            return;
        }
        
        for (int j = 0; j <= 9; j++){
            if (j == 0 && output.size() == 0) continue;
            int diff = abs((output.back() - '0') - j);
            if (output.size() == 0 || diff == k){
                char ch = (j + '0');
                solve(n, k, ans, output + ch);
            }
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        string output;
        solve(n, k, ans, output);
        return ans;
    }
};