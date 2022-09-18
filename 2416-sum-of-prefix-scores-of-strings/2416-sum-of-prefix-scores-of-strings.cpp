class TrieNode{
public:
    unordered_map<char, pair<int, TrieNode*> > child;
};
class Solution {
public:
    void insertion(string &s, TrieNode* &root){
        TrieNode* itr = root;
        for (int i = 0; i < s.size(); i++){
            if (itr->child.count(s[i])){
                int count = itr->child[s[i]].first + 1;
                TrieNode* temp = itr->child[s[i]].second;

                itr->child[s[i]] = {count, temp};
                itr = itr->child[s[i]].second;
            }
            else {
                TrieNode* newNode = new TrieNode();
                itr->child[s[i]] = {1, newNode};
                itr = itr->child[s[i]].second;
            }
        }
        
    }
    int counter(string &s, TrieNode* &root){
        int count = 0;
        TrieNode* itr = root;
        for (int i = 0; i < s.size(); i++){
            count += itr->child[s[i]].first;
            itr = itr->child[s[i]].second;
        }
        return count;
    }
    vector<int> sumPrefixScores(vector<string>& words) {
        int n = words.size();
        vector<int> ans;
        TrieNode * root = new TrieNode();
        for (auto &word : words){
            insertion(word, root);
        }
        
        for (auto &word : words){
            int count = counter(word, root);
            ans.push_back(count);
        }
        return ans;
    }
};