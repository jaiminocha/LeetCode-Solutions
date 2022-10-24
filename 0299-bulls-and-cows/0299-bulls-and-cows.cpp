class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> m;
        int bulls = 0, cows = 0;
        int n = secret.size();
        
        unordered_set<int> s;
        for (int i = 0; i < n; i++){
            if (secret[i] == guess[i]){
                bulls++;
                s.insert(i);
                continue;
            }
            m[secret[i]]++;
        }
        
        for (int i = 0; i < n; i++){
            if (s.count(i)) continue;
            else if (m.count(guess[i])){
                m[guess[i]]--;
                cows++;
                if (m[guess[i]] == 0) m.erase(guess[i]);
            }
        }
        
        string ans = to_string(bulls) + "A" + to_string(cows) + "B";
        return ans;
    }
};