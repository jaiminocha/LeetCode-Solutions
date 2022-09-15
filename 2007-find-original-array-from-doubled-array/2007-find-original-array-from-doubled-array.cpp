class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
         int n = changed.size();
        if (n & 1) return {};

        sort(begin(changed), end(changed));
        unordered_map<int, int> cover; // element, freq

        vector<int> ans(n / 2);
        int idx = 0;
        for (int i = 0; i < n; i++){
            if (!cover[(changed[i])]){
                cover[changed[i] * 2]++;
                if (idx >= n / 2) return {};
                ans[idx++] = changed[i];
            }
            else {
                cover[changed[i]]--;
                if (cover[changed[i]] < 0) return {};
            }
        }
        for (auto x : cover) {
            if (x.second) return {};
        }
        return ans;
    }
};