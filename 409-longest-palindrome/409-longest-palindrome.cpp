class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> m;
        for (auto c : s){
            m[c]++;
        }
        int ans = 0;
        bool one = false;
        for (auto x : m){
            int pairs = x.second / 2;
            if (x.second % 2) one = true;
            ans += (pairs * 2);
        }
        if (one) ans++;
        return ans;
    }
};