class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        vector<long long int> preSum(n);
        long long int sum = 0;
        for (int i = 0; i < n; i++){
            sum += nums[i];
            preSum[i] = sum;
        }
        int ans = 0, minDiff = INT_MAX;
        for (int i = 0; i < n; i++){
            int left_size = i + 1, right_size = n - i - 1;
            long long int lsum = preSum[i], rsum = preSum[n - 1] - preSum[i];
            long long int l_avg = left_size == 0 ? 0 : lsum / left_size, r_avg = right_size == 0 ? 0 : rsum / right_size;
            long long int diff = abs(l_avg - r_avg);
            //cout << "index : " << i << " " << diff << endl;
            if (diff < minDiff){
                minDiff = diff;
                ans = i;
            }
        }
        return ans;
    }
};