class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        int n = arr.size();
        map<int, int> m, m2;
        for (int x : arr){
            m[x]++;
        }
        sort(begin(arr), end(arr));
        for (int i = 0; i < n; i++){
            int x1 = arr[i];
            
            if (m[x1] == 0 && m2[x1] != 0) continue;
            double val = x1 > 0 ? 2 * x1 : (double)(x1 / 2.0);
            if (val != ceil(val)) return false;
            if (m[val] == 0){
                return false;
            }
            m[x1]--;
            m[val]--;
            m2[val]++;
            
        }
        for (auto x : m) {
            if (x.second != 0) return false;
        }
        return true;
    }
};