class Solution {
public:
    const int mod = 1e4 + 7;
    int firstMissingPositive(vector<int>& nums) {
        // if (nums.size() == 1){
        //     if (nums[0] == 1) return 2;
        //     else return 1;
        // } 
        // int n = nums.size();
        // for (int i = 0; i < n; i++){
        //     if (nums[i] >= 1 && nums[i] < n && nums[i] != i){
        //         int ind = nums[i];
        //         swap(nums[ind], nums[i]);
        //         ind = nums[i];
        //         while (ind < n && ind >= 0){
        //             if (nums[i] == i) break;
        //             swap(nums[ind], nums[i]);
        //             if (ind == nums[i]) break;
        //             ind = nums[i];
        //         }
        //     }  
        // }
        // for (auto x : nums) cout << x << " ";
        // cout << "\n";
        // long long int ans = -1, noOne = 0;
        // long long int sum = 0;
        // for (int i = 1; i < n; i++){
        //     if (nums[i] != i){
        //         ans = i;
        //         return ans;
        //         noOne++;
        //     }
        //     sum += nums[i];
        // }
        // long long int formSum = 0;
        // if (n&1) {            
        //     formSum = (n%mod)*(((n - 1)/2)%mod)%mod;
        // }
        // else formSum = ((n/2)%mod)*((n - 1)%mod)%mod;
        // sum %= mod;
        // cout << "sum: " << sum << " " << formSum << "\n";
        // // cout << "noone: " << noOne << " " << n - 1 << "\n";
        // if (ans == -1 && sum == formSum && noOne == 0) {
        //     if (nums[0] == n) return n + 1;
        //     ans = n;
        //     return ans;
        // }
        // return ans;
        
        
        
        int n = nums.size();
        int ans = -1;
        
        for (int i = 0; i < n; i++){
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]){
                swap(nums[nums[i] - 1], nums[i]);
            }
        }
        for (int i = 0; i < n; i++){
            //cout << nums[i] << " ";
            if (nums[i] != i + 1){
                ans = i + 1;
                break;
            }
        }
        return ans == -1 ? n + 1 : ans;
    }
};

/*
       0 1  2 3
nums: [3,4,-1,1]   // i = 0
correct the ones who are in the range [1, n - 1] => [1,3], since (n == 4)

step1:
nums: [1,4,-1,3]   // i = 0

step2:
nums: [4,1,-1,3]   // i = 1

step3:
nums: [4,1,-1,3]   // i = 2

step4: 
nums: [4,1,-1,3]   // i = 3

*/