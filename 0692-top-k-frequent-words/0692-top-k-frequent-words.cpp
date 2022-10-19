typedef pair<string, int> node;
class Solution {
public:
    class Compare{
    public:
        bool operator()(node a, node b) {
            if (a.second == b. second){
                return a.first > b.first;
            }
            return a.second < b.second;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;
        for (auto s : words){
            m[s]++;
        }
        vector<string> ans;
        priority_queue<node, vector<node>, Compare > pq;
        for (auto x : m){
            pq.push({x.first, x.second});
        }
        
        while (!pq.empty() && k--){
            node x = pq.top();
            pq.pop();
            ans.push_back(x.first);
        }
        
        return ans;
    }
};