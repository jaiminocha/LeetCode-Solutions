class Solution {
public:
    bool isVowel(char c){
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){
            return true;
        }
        return false;
    }
    string reverseVowels(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r){
            while (l < r && !isVowel(s[l])){
                l++;
            }
            while (l < r && !isVowel(s[r])){
                r--;
            }
            if (isVowel(s[l]) && isVowel(s[r])){
                swap(s[l++], s[r--]);
            }
        }
        return s;
    }
};