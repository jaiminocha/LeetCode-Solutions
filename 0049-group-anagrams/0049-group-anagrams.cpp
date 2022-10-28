class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        if (strs.size() == 0) return ans;
        unordered_map<string, vector<string>> m;
        for (auto &x : strs){
            string temp = x;
            sort(temp.begin(), temp.end());
            vector<string> t;
            if (m.count(temp) > 0){
                for (auto &y : m[temp]){
                    t.push_back(y);
                }
            }
            t.push_back(x);
            m[temp] = t;
            
        }
        for (auto &x : m){
            ans.push_back(move(x.second)); // don't copy make reference
        }
        return ans;
    }
};