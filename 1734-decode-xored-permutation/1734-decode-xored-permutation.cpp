class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int n = encoded.size() + 1;
        
        int totalXor = 0;
        for (int i = 1; i <= n; i++){
            totalXor ^= i;
        }
        int en_xor = 0;
        for (int i = 1; i < n - 1; i += 2){
            en_xor ^= encoded[i];
        }
        vector<int> ans(n);
        ans[0] = totalXor ^ en_xor;
        // cout << totalXor << " " << ans[0];
        for (int i = 1; i < n; i++){
            ans[i] = ans[i - 1] ^ encoded[i - 1];
        }
        return ans;
    }
};