class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int m = a.size() - 1;
        int n = b.size() - 1;
        int carry = 0;
        
        while (m >= 0 || n >= 0 || carry){
            if (m >= 0){
                carry += (a[m--] - '0'); 
            }
            if (n >= 0){
                carry += (b[n--] - '0');
            }
            char digit = ((carry % 2) + '0');
            ans.push_back(digit);
            carry /= 2;
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};