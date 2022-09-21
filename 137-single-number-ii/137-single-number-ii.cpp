class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> m;
        for (auto x : nums){
            m[x]++;
        }
        int ans = 0;
        for (auto x : m){
            if (x.second == 1){
                ans = x.first;
                break;
            } 
        }
        return ans;
    }
};