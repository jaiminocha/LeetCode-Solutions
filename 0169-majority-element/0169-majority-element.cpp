class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element = -1, counter = 0;
        
        for (auto x : nums){
            if (element == x){
                counter++;
            }
            else if (counter > 0){
                counter--;
            }
            else {
                element = x;
                counter = 1;
            }
        }
        return element;
    }
};