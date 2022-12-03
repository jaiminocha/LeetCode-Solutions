class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m;
        priority_queue<pair<int, char>> pq; 
        
        for (auto c : s){
            m[c]++;
        }
        
        string ans = "";
        for (auto x : m){
            int freq = x.second;
            char ch = x.first;
            pq.push({freq, ch});
        }
        
        while (!pq.empty()){
            int freq = pq.top().first;
            char ch = pq.top().second;
            pq.pop();
            
            while (freq--){
                ans.push_back(ch);
            }
        }
        
        return ans;
    }
};