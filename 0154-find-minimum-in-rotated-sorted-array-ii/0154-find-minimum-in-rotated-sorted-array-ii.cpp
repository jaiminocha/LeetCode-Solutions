class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        int s = 0, e = n - 1;
        if (nums[s] < nums[e]) return nums[s];
        
        while (s <= e){
            int mid = s + (e - s) / 2;
            if (nums[mid] > nums[e]){
                s = mid + 1;
            }
            else if (nums[mid] < nums[s]){
                e = mid;
                s++;
            }
            else {
                e--;
                // s++;
            }
        }
        return nums[s];
    }
};