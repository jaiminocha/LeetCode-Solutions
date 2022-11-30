class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq;
        for (auto x : arr){
            freq[x]++;
        }
        set<int> s;
        for (auto x : freq){
            s.insert(x.second);
        }
        if (s.size() == freq.size()){
            return true;
        }
        return false;
    }
};