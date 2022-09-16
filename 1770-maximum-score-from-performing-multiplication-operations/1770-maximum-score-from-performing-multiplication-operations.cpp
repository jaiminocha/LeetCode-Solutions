class Solution {
public:
    int solve(vector<int> &nums, vector<int> &mul, int idx, int s, vector<vector<int> > &dp) {
        if (idx == mul.size()){
            return 0;
        }

        if (dp[idx][s] != INT_MIN){
            return dp[idx][s];
        }

        // add
        int op1 = (nums[s] * mul[idx]) + solve(nums, mul, idx + 1, s + 1, dp); 
        int op2 = (nums[(nums.size() - 1) - (idx - s)] * mul[idx]) + solve(nums, mul, idx + 1, s, dp);

        return dp[idx][s] = max(op1, op2);
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size(), m = multipliers.size();
        vector<vector<int> > dp(m + 1, vector<int> (m + 1, INT_MIN)); 
        return solve(nums, multipliers, 0, 0, dp);
    }
};