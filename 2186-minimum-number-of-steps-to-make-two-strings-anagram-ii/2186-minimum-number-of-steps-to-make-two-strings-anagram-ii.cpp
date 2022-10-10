class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int> m1, m2;
        
        for (auto x : s){
            m1[x]++;
        }
        for (auto x : t){
            m2[x]++;
        }
        int ans = 0;
        for (auto x : m1){
            if (m2.count(x.first)){
                int diff = abs(x.second - m2[x.first]);
                ans += diff;
                // m1.erase(x.first);
                // m2.erase(x.first);
                m1[x.first] = 0;
                m2[x.first] = 0;
            }
            else ans += x.second;
        }
        for (auto x : m2){
            if (m1.count(x.first)){
                int diff = abs(x.second - m1[x.first]);
                ans += diff;
                // m1.erase(x.first);
                // m2.erase(x.first);
                m1[x.first] = 0;
                m2[x.first] = 0;
            }
            else ans += x.second;
        }
        return ans;
    }
};