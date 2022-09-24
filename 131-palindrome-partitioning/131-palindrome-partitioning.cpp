class Solution {
public:
    bool isPalindrome(string &s, int i, int j){
        while (i < j){
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }
    void solve(string &s, vector<vector<string> > &ans, vector<string> parts, int i){
        if (i == s.size()){
            
            ans.push_back(parts);
            return;
        }
        int j = i;
        
        // include
        for (; j < s.size(); j++){
            if (isPalindrome(s, i, j)){
                string temp = s.substr(i, j - i + 1);
                parts.push_back(temp);
                solve(s, ans, parts, j + 1);
                parts.pop_back();
            }
        }
        
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string> > ans;
        int n = s.length();
        
        vector<string> parts;
        solve(s, ans, parts, 0);
        return ans;
    }
};