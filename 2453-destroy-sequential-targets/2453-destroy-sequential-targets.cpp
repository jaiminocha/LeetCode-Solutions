class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        
        int n = nums.size();
        if (n == 1) return nums[0];
        unordered_map<int, int> m;
        
        int ans = INT_MAX, times = -1;
        
        for (int i = 0; i < n; i++){
            int rem = nums[i] % space;
            m[rem]++;
            times = max(times, m[rem]);
        }
        
        cout << times;
        for (auto x : nums){
            int r = (x % space);
            // cout << "r: " << r << endl;
            if (m[r] == times){
                ans = min(ans, x);
            }
        }
        
        return ans;
    }
};