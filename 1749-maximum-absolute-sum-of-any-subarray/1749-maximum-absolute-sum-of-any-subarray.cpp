class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum = INT_MIN, minSum = INT_MAX;
        int n = nums.size(), sum = 0, s = 0;
        
        for (int i = 0; i < n; i++){
            // max sum 
            sum += nums[i];
            maxSum = max(maxSum, sum);
            if (sum < 0){
                sum = 0;
            }
            
            // min sum
            s += nums[i];
            minSum = min(minSum, s);
            if (s > 0){
                s = 0;
            }
        }
        return max(maxSum, abs(minSum));
    }
};