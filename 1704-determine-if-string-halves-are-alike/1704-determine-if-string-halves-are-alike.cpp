class Solution {
public:
    bool halvesAreAlike(string s) {
        unordered_set<int> se;
        int c1 = 0, c2 = 0;
        int n = s.size();
        vector<char> v = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        for (auto x : v) se.insert(x);
        for (int i = 0; i < n; i++){
            if (i < n / 2){
                if (se.count(s[i])){
                    c1++;
                }
            }
            else {
                if (se.count(s[i])){
                    c2++;
                }
            }
        }
        return c1 == c2;
    }
};