class Solution {
public:
    bool isPossible(unordered_set<char> &s, string str){
        int i = 0;
        unordered_set<char> se;
        while (i < str.size()){
            if (s.count(str[i])){
                return false;
            }
            if (se.count(str[i])) return false;
            se.insert(str[i]);
            i++;
        }
        return true;
    }
    int solve(vector<string> &a, int i, unordered_set<char> s){
        if (a.size() == i){
            return s.size();
        }
        int op1 = 0, op2 = 0;
        // exclude
        op2 = solve(a, i + 1, s);
        // include
        if (isPossible(s, a[i])){
            int j = 0;
            while (j < a[i].size()) {
                s.insert(a[i][j++]);
            }
            op1 = solve(a, i + 1, s);
        }
        return max(op1, op2);
    }
    
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        int ans = 0;
        for (int i = 0; i < n; i++){
            unordered_set<char> s1;
            int idx = 0;
            bool flag = false;
            while (idx != arr[i].size()) {
                if (s1.count(arr[i][idx])) {
                    flag = true;
                    break;
                }
                s1.insert(arr[i][idx++]);
            }
            if (flag) continue;
            int single_len = arr[i].size();
            ans = max(ans, single_len);
            int res = solve(arr, i + 1, s1);
            //cout << arr[i] << " " << res << endl;
            ans = max(ans, res);
        }
        return ans;
    }
};