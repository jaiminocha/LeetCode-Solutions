const int mod = 1e9 + 7;
class Solution {
public:
    unordered_map<int, int> m;
    long long solve(int l, int h, int z, int o, long long len){
        if (len > h) return 0;
        int ans = 0;
        if (len >= l && len <= h){
            ans = 1;
        }
        if (m.count(len)) return m[len];
        return m[len] = (ans + solve(l, h, z, o, len + z) + solve(l, h, z, o, len + o)) % mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        long long ans = 0;
        ans = solve(low, high, zero, one, 0) % mod;
        return ans % mod;
    }
};