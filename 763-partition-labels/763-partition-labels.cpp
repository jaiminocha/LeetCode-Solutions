class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> ans;
        unordered_map<char, pair<int, int> > m;
        for (int i = 0; i < n; i++){
            char ch = s[i];
            if (m.count(ch)){
                m[ch].second = i;
            }
            else {
                m[ch] = {i, i};
            }
        }
        for (int i = 0; i < n; i++){
            char ch = s[i];
            int st = m[ch].first;
            int e = m[ch].second;
            if (st == e){
                ans.push_back(1);
            }
            else {
                int maxRange = e;
                for (int j = i + 1; j <= maxRange; j++){
                    char ch1 = s[j];
                    int range = m[ch1].second;
                    if (maxRange < range){
                        maxRange = range;
                    }
                }
                int len = maxRange - i + 1;
                ans.push_back(len);
                i = maxRange;
            }
        }
        return ans;
    }
};