class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = 0, ansDiff = INT_MAX;
        int i = 0, j = nums.size() - 1;
        sort(nums.begin(), nums.end());
        while (i < j){
            int k = i + 1;
            j = nums.size() - 1;
            while (k < j){
                int sum3 = nums[i] + nums[j] + nums[k];
                // cout << nums[i] << " " << nums[j] << " " << nums[k] << "\n";
                if (sum3 == target){
                    return sum3;
                }
                else if (sum3 < target){
                    k++;
                }
                else {
                    j--;
                }
                
                int diff = abs(sum3 - target);
                // cout << "ans Diff: " << ansDiff << ", diff:" << diff << "\n";
                if (ansDiff > diff){
                    // cout << "sum: " << sum3 << "\n";
                    ans = sum3;
                    ansDiff = diff;
                }
            }
            i++;
        }
        return ans;
    }
};