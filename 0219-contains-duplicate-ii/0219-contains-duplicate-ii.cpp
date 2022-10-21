class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int ind2 = -1;
        for (int i = 0; i < nums.size(); i++){
            if (m.count(nums[i]) > 0) {
                ind2 = i;  
                int check = i - m[nums[i]];
                //if (check < 0) check *= (-1);
                //cout << i << " " << m[nums[i]] << " " << check << endl;
                if (check <= k) return true;
            }
            m[nums[i]] = i;
        }
        return false;
    }
};