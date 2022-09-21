class Solution {
public:
    const int mod = 1e4 + 7;
    int findDuplicate(vector<int>& nums) {
        // int output=0;
        // unordered_map<int, int> m;
        // for (auto i : nums){
        //     m[i]++;
        // }
        // for (auto x : m){
        //     if (x.second >= 2) {
        //         output = x.first;
        //         break;
        //     }
        // }
        // return output;
        
        int n = nums.size();
        
        for (int i = 0; i < n; i++){
            int idx = abs(nums[i]) - 1;
            if (nums[idx] < 0){
                return idx + 1;
            }
            nums[idx] *= (-1);
        }
        return -1;
    }
};