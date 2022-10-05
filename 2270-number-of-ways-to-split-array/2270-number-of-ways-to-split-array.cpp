class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long int totalSum = 0;
        for (int i = 0; i < n; i++){
            totalSum += nums[i];
        }
        
        long long int sum = 0;
        int counter = 0;
        for (int i = 0; i < n - 1; i++){
            sum += nums[i];
            if (sum >= (totalSum - sum)){
                counter++;
            }
        }
        return counter;
    }
};