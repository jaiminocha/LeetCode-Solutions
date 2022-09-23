int mod = 1e9 + 7;
class Solution {
public:
    string decToBinary(int n){
        string res;
        bool first = false;
        for (int i = 31; i >= 0; i--){
            int val = n >> i;
            if (val & 1){
                first = true;
            }
            if (!first) continue;
            if (val & 1){
                res.push_back('1');
            }
            else {
                res.push_back('0');
            }
        }
        return res;
    }
    int concatenatedBinary(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++){
            string bin = decToBinary(i);
            int num = i, len = bin.length();
            for (int j = 0; j < len; j++){
                int val = bin[j] == '0' ? 0 : 1;
                ans = (((ans * 2) % mod) + val) % mod;
            }
        }
        return ans;
    }
};