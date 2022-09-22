class Solution {
public:
    int stoneDifference(vector<int> &p, int s, int e, vector<vector<int> > &dp){
        if (s > e){
            return 0;
        }
        if (dp[s][e] != INT_MIN){
            return dp[s][e];
        }
        return dp[s][e] = max(p[s] - stoneDifference(p, s + 1, e, dp), p[e] - stoneDifference(p, s, e - 1, dp));
    }
    bool stoneGame(vector<int>& piles) {
        vector<vector<int> > dp(501, vector<int> (501, INT_MIN));
        return stoneDifference(piles, 0, piles.size() - 1, dp) > 0;
    }
};