class Solution {
public:
    int solve(string &s, int n, string output, int i, vector<int> &dp){
        if (i == n){
            if (output.size() == n) {
                cout << output << "\n";
                return 1;
            }
            return 0;
        }
        if (dp[i] != -1){
            return dp[i];
        }
        int ways1 = 0, ways2 = 0;
        // include
        if (s[i] != '0' && ((i < n - 1 && s[i + 1] != '0') || (i == n - 1))){
            output.push_back(s[i]);
            ways1 = solve(s, n, output, i + 1, dp);
            output.pop_back();
        }
        if (i < n - 1 && s[i] != '0' && ((s[i] == '1') || (s[i] == '2' && s[i + 1] <= '6'))){
            output.push_back(s[i]);
            output.push_back(s[i + 1]);
            ways2 = solve(s, n, output, i + 2, dp);
            output.pop_back();
            output.pop_back();
        }
        return dp[i] = ways1 + ways2;
    }
    int numDecodings(string s) {
        int n = s.size();
        if (n == 1) return s[0] == '0' ? 0 : 1;
        int count = 0;
        string output;
        vector<int> dp(n, -1);
        return solve(s, n, output, 0, dp);
        return count;
    }
};