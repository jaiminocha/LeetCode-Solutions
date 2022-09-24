class Solution {
public:
    bool isPalindrome(string &s, int i, int j){
        while (i < j){
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }
    int solve(string &s, int i, vector<int> &dp){
        if (i == s.size()){
            return 0;
        }
        if (dp[i] != -1){
            return dp[i];
        }
        int cut = 0, minCuts = INT_MAX;
        for (int j = i; j < s.size(); j++){
            if(isPalindrome(s, i, j)){
                cut = 1 + solve(s, j + 1, dp);
                minCuts = min(minCuts, cut);
            }
        }
        return dp[i] = minCuts;
    }
    int minCut(string s) {
        vector<int> dp(s.size(), -1);
        return solve(s, 0, dp) - 1;
    }
};