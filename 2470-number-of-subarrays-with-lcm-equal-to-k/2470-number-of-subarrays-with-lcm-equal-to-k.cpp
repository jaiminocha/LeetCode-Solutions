class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int n = nums.size();
        int counter = 0;
        for (int i = 0; i < n; i++){
            long long temp = nums[i];
            if (temp > k) continue;
            for (int j = i; j < n; j++){
                if (nums[j] > k || temp > k) break;
                long long lcm = (temp * nums[j]) / gcd(temp, nums[j]);
                if (lcm == k) counter++;
                temp = lcm;
            }
        }
        return counter;
    }
};