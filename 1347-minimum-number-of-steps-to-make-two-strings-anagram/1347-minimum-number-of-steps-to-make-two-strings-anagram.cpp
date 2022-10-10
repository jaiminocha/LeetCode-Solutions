class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int> m;
        
        for (auto x : s){
            m[x]++;
        }
        for (auto x : t){
            m[x]--;
        }
        
        int ans = 0;
        for (auto x : m){
            //cout << x.first << " " << x.second << "\n";
            ans += abs(x.second);
        }
        return ans / 2;
    }
};