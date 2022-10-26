class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        m[0] = -1;
        int n = nums.size();
        
        int sum = 0;
        for (int i = 0; i < n; i++){
            sum += nums[i];
            int rem = sum % k;
            
            if (m.count(rem)){
                if (i - m[rem] > 1){
                    //cout << i << " " << m[rem] << endl;
                    return true;
                }
            }else 
                m[rem] = i;
        }
        
        return false;
    }
};