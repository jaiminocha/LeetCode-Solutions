class Solution {
public:
    bool isPalindrome(string &s, int l, int r){
        while(l<r){
            if(s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;
        unordered_map<string, int> mp;
        set<int> s;
        
        for(int i=0;i<words.size();i++){
            mp[words[i]] = i;
            s.insert(words[i].size());
        }
        
        for(int i=0;i<words.size();i++){
            string str = words[i];
            int len = str.size();
            reverse(str.begin(),str.end());
            
            if(mp.count(str) && mp[str]!=i){
                ans.push_back({i,mp[str]});
            }
            
            auto a = s.find(len);
            for(auto it = s.begin();it!=a; ++it){
                int d = *it;
                
                if(isPalindrome(str,0,len-d-1) && mp.count(str.substr(len-d))){
                    ans.push_back({i, mp[str.substr(len-d)]});
                }
                
                if(isPalindrome(str,d,len-1) && mp.count(str.substr(0,d))){
                    ans.push_back({mp[str.substr(0,d)],i});
                }
                
            }
            
        }
        return ans;
    }
};