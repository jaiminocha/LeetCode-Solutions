class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        if (m > n) return "";
        
        unordered_map<char, int> freq;
        for (auto x : t) freq[x]++;
        int l = -1, r = -1;
        
        string ans = "";
        
        int counter = 0;
        unordered_map<char, int> mp;
        int minLen = INT_MAX;
        
        while (1){
            bool f1, f2;
            f1 = f2 = false;
            while (r < n - 1 && counter < m){
                r++;
                mp[s[r]]++;
                if (freq.count(s[r]) && mp[s[r]] <= freq[s[r]]){
                    counter++;
                }
                f1 = true;
            }
            
            while (l < r && counter == m){
                string temp = s.substr(l + 1, r - l);
                if (ans.size() == 0 || ans.size() > temp.size()){
                    ans = temp;
                }
                l++;
                mp[s[l]]--;
                if (mp[s[l]] == 0) mp.erase(s[l]);
                if (mp[s[l]] < freq[s[l]]){
                    counter--;
                }
                f2 = true;
            }
            if (!f1 && !f2) break;
        }
        
        
//         while (l < n && r < n){
//             if (counter < m){
//                 if (freq.count(s[r])){
//                     counter++;   
//                     mp[s[r]]++;
//                     if (mp.count(s[r]) && mp[s[r]] > freq[s[r]]) counter--;
//                 }
                
//                 r++;
//                 int len = r - l + 1;
//                 if (counter == m && len < minLen) {
//                     minLen = len;
//                     ans = s.substr(l, len);
//                 }
//             }
//             else if (counter == m){
//                 if (mp.count(s[l])){
//                     int val = --mp[s[l]];
//                     if (val < freq[s[l]]){
//                         counter--;
//                     }
//                 }
//                 l++;
//                 int len = r - l + 1;
//                 if (counter == m && len < minLen){
//                     minLen = len;
//                     ans = s.substr(l, len);
//                 }
//             }
//         }
        return ans;
    }
};