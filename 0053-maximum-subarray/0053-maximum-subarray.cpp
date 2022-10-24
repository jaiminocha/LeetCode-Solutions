class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // int maxSum = nums[0], maxYet = 0;
        // int flag = 0, maybeMax = nums[0];
        // for (auto num : nums){
        //     maxYet = maxYet + num;
        //     if (maxSum < maxYet){
        //         maxSum = maxYet;
        //     }
        //     if (maxYet<0){
        //         maybeMax = max(maybeMax, maxYet);
        //         maxYet = 0;
        //         flag++;
        //     }
        // }
        // if (flag == nums.size()) return maybeMax;
        // return maxSum;
        
        int maxSum = INT_MIN;
        int sum = 0, n = nums.size();
        
        for (int i = 0; i < n; i++){
            sum += nums[i];
            maxSum = max(maxSum, sum);
            if (sum < 0){
                sum = 0;
            }
        }
        return maxSum;
    }
};