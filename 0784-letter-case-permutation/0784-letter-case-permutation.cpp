class Solution {
public:
    void solve(string str, unordered_set<string> &s, int i){
        if (i == str.size()){
            s.insert(str);
            return;
        }
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')){
            // op 1
            solve(str, s, i + 1);
            //op2
            char ch = str[i];
            if (islower(ch)){
                str[i] = toupper(str[i]);
            }
            else {
                str[i] = tolower(str[i]);
            }
            solve(str, s, i + 1);
            str[i] = ch;
        }
        else {
            solve(str, s, i + 1);
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        unordered_set<string> se;
        solve(s, se, 0);
        for (auto x : se) ans.push_back(x);
        return ans;
    }
};