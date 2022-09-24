class Solution {
public:
    // difference of scores
    int difference(vector<int> &nums, int s, int e, vector<vector<int> > &dp){
        if (s > e){
            return 0;
        }
        
        if (dp[s][e] != -1){
            return dp[s][e];
        }
        
        return dp[s][e] = max(nums[s] - difference(nums, s + 1, e, dp), nums[e] - difference(nums, s, e - 1, dp));
    }
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int> > dp(n + 1, vector<int> (n + 1, -1));
        return difference(nums, 0, n - 1, dp) >= 0;
    }
};