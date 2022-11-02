class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wl;
        for(auto w : wordList) wl.insert(w);
        unordered_set<string> visited;
        wl.insert(beginWord);
        visited.insert(beginWord);
        queue<string> pn;
        pn.push(beginWord);
        int level = 1;
        vector<unordered_set<char> > dict(beginWord.size());
        for (auto w : wl){
            int i = 0;
            for (auto c : w){
                dict[i++].insert(c);
            }
        }
        while (!pn.empty()){
            int n = pn.size();
            for (int i = 0; i < n; i++){
                string node = pn.front();
                pn.pop();
                if (node == endWord && wl.count(endWord)){
                    return level;
                }
                for (int i = 0; i < node.size(); i++){
                    unordered_set<char> ts = dict[i];
                    for (auto x : ts){
                        string temp = node;
                        temp[i] = x;
                        if (wl.count(temp) && !visited.count(temp)){
                            // cout << temp << " ";
                            visited.insert(temp);
                            pn.push(temp);
                        }
                    }
                }//cout << endl;
            }
            level++;
        }
        return 0;
    }
};