class Solution {
public:
    bool closeStrings(string word1, string word2) {
        set<char> s1, s2;
        vector<int> v1(26, 0), v2(26, 0);
        
        for (auto x : word1){
            s1.insert(x);
            v1[x - 'a']++;
        }
        for (auto x : word2){
            s2.insert(x);
            v2[x - 'a']++;
        }
        sort(begin(v1), end(v1));
        sort(begin(v2), end(v2));
        return (v1 == v2 && s1 == s2);
    }
};