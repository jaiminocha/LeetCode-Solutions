class Solution {
public:
    vector<int> countBits(int n) {
        if (n == 0) return {0};
        vector<int> ans(n + 1, 0);
        ans[0] = 0;
        ans[1] = 1;
        int factor = 2;
        for (int i = 2; i <= n; i++){
            if (i == factor){
                factor *= 2;
                ans[i] = 1;
            }
            else {
                ans[i] = ans[factor/2] + ans[i - (factor / 2)];
            }
        }
        return ans;
    }
};