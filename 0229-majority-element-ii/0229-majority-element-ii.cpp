class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> ans;
        int e1 = -1, count1 = 0;
        int e2 = -1, count2 = 0;
        for (auto x : nums){
            if (x == e1){
                count1++;
            }
            else if (x == e2){
                count2++;
            }
            else if (count1 == 0){
                e1 = x;
                count1 = 1;
            }
            else if (count2 == 0){
                e2 = x;
                count2 = 1;
            }
            else {
                count1--;
                count2--;
            }
        }
        count1 = 0, count2 = 0;
        for (auto x : nums){
            if (x == e1) count1++;
            else if (x == e2) count2++;
        }
        // cout << e1 << " " << e2 << endl;
        if (count1 > (n / 3)) ans.push_back(e1);
        if (count2 > (n / 3)) ans.push_back(e2);
        return ans;
    }
};