class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int perimeter = 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 1; i < n - 1; i++){
            cout << nums[i] << " ";
            if (nums[i - 1] + nums[i] > nums[i + 1]) perimeter = nums[i - 1] + nums[i] + nums[i + 1];
        }
        return perimeter;
    }
};