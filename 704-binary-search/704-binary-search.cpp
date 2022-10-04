class Solution {
public:
    // Iterative
    // int search(vector<int>& nums, int target) {
    //     int s = 0, e = nums.size() - 1;
    //     while (s <= e){
    //         int mid = s + (e - s)/2;
    //         if (nums[mid] == target) return mid;
    //         else if (nums[mid] < target) {
    //             s = mid + 1;
    //         }
    //         else e = mid - 1;
    //     }
    //     return -1;
    // }
    
    // with Recursion
    int helper(vector<int>& nums, int target, int s, int e){
        if (s > e) return -1;
        int mid = s + (e - s)/2;
        int ans = -1;
        if (nums[mid] == target) return mid;
        else if (nums[mid] > target) {
            ans = helper(nums, target, s, mid - 1);
        }
        else {
            ans = helper(nums, target, mid + 1, e);
        }
        return ans;
    }
    
    int search(vector<int>& nums, int target) {
        int s = 0, e = nums.size() - 1;
        return helper(nums, target, s, e);
    }
};