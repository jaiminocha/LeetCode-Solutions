class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        vector<map<int, int>> vm(n); // index, [difference and frequency]
        
        for (int i = 1; i < n; i++){
            for (int j = 0; j < i; j++){
                long long diff = ((long long)nums[j] - nums[i]);
                if (diff >= INT_MAX || diff <= INT_MIN) continue;
                diff = (int)diff;
                int freq = 0;
                if (vm[j].find(diff) != vm[j].end()){
                    freq = vm[j][diff];
                }
                vm[i][diff] += (freq + 1);
                count += freq;
            }
        }
        return count;
    }
};