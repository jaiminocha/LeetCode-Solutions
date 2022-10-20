class Solution {
public:
    string intToRoman(int num) {
        vector<string> rom{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        vector<int> vals{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string ans = "";
        
        for (int i = 0; i < rom.size() && num != 0; i++){
            int val = vals[i];
            string str = rom[i];
            while (num - val >= 0){
                num -= val;
                ans += str;
            }
        }
        return ans;
    }
};