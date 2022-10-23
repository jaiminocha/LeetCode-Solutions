class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int twice = -1, missing = -1, n = nums.size();
        
        for (int i = 0; i < n; i++){
            if (nums[abs(nums[i]) - 1] < 0){
                twice = abs(nums[i]);
            }
            else {
                nums[abs(nums[i]) - 1] *= -1;
            }
        }
        
        for (int i = 0; i < n; i++){
            if (nums[i] > 0) missing = i + 1;
        }
        return {twice, missing};
    }
};