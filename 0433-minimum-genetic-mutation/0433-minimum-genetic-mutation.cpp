class Solution {
public:
    // why this approach fails? Because in the process of conversion some 
    // strings are not in bank but the end result might be there.
    // take a case where the end is stored in bank, but while converting start
    // to end there is a string in between which is not in bank, therefore there
    // is no way we can reach the end string.
    
//     int minMutation(string start, string end, vector<string>& bank) {
//         int count = 0;
//         int n = bank.size(), i;
//         for (i = 0; i < n; i++){
//             if (end == bank[i]) break;
//         }
//         if (i == n) return -1;
        
//         for (int i = 0; i < 8; i++){
//             if (start[i] != end[i]) count++;
//         }
//         return count;
//     }
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> visited;
        unordered_set<string> b;
        for (auto x : bank) b.insert(x);
        b.insert(start);
        visited.insert(start);
        queue<string> pn;
        pn.push(start);
        int level = 0;
        string dict = "ACGT";
        while (!pn.empty()){
            int n = pn.size();
            for (int i = 0; i < n; i++){
                string node = pn.front();
                pn.pop();
                if (node == end && b.count(end)){
                    return level;
                }
                for (char ch : dict){
                    for (int i = 0; i < node.size(); i++){
                        string temp = node;
                        temp[i] = ch;
                        if (b.count(temp) && visited.find(temp) == visited.end()){
                            //cout << temp << " ";
                            visited.insert(temp);
                            pn.push(temp);
                        }
                    }
                }   
            }
            level++;
        }
        return -1;
    }
};