class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, char> m1, m2;
        int i = 0;
        for (auto ch : s){
            if (m1.count(ch)){
                if (m1[ch] != t[i]){
                    return false;
                }
            }
            else m1[ch] = t[i];
            if (m2.count(t[i])){
                if (m2[t[i]] != ch) return false;
            }
            else m2[t[i]] = ch;
            i++;
        }
        return true;
    }
};