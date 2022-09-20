class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        
        vector<vector<int> > dp(n + 1, vector<int> (m + 1, 0));
        
        int maxLen = 0;
        for (int r = 1; r <= n; r++){
            for (int c = 1; c <= m; c++){
                if (nums1[r - 1] == nums2[c - 1]){
                    dp[r][c] = 1 + dp[r - 1][c - 1];
                }
                maxLen = max(maxLen, dp[r][c]);
            }
        }
        return maxLen;
    }
};