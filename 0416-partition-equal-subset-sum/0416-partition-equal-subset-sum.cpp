class Solution {
public:
    bool solve(vector<int> &nums, int n, int req, int sum, int i, vector<vector<int> > &dp){
        if (i == n){
            if (sum == req){
                return true;
            }
            return false;
        }
        if (dp[i][sum] != -1) return dp[i][sum];
        bool op1 = false;
        if (sum + nums[i] <= req) op1 = solve(nums, n, req, sum + nums[i], i + 1, dp);
        bool op2 = solve(nums, n, req, sum, i + 1, dp);
        
        return dp[i][sum] = (op1 || op2);
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int totalSum = accumulate(begin(nums), end(nums), 0);
        if (totalSum % 2) return false;
        vector<vector<int> > dp(n + 1, vector<int> (totalSum/2 + 1, -1));
        return solve(nums, n, totalSum / 2, sum, 0, dp);
    }
};