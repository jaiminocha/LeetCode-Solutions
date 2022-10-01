class Solution {
public:
    bool equalFrequency(string word) {
        int n = word.size();
        unordered_map<char, int> m, m1, m2;
        
        int maxFreq = INT_MIN, minFreq = INT_MAX;
        char maxCh, minCh;
        for (auto l : word){
            m[l]++;
        }
        for (auto x : m){
            unordered_map<char, int> m0;
            char curr = x.first;
            bool once = true;
            for (auto l : word){
                if (once && curr == l){
                    once = false;
                    continue;
                }
                m0[l]++;
            }
            int freq = 0;
            for (auto y : m0){
                freq = y.second;
                break;
            }
            bool possible = true;
            for (auto y : m0){
                if (y.second != freq){
                    possible = false;
                    break;
                }
            }
            if (possible) return true;
        }
        return false;
//         for (auto x : m){
//             maxCh = x.first;
//             maxFreq = x.second;
//             minFreq = x.second;
//             break;
//         }
        
//         for (auto x : m){
//             if (x.second > maxFreq){
//                 maxFreq = x.second;
//                 maxCh = x.first;
//             }
//             if (x.second < minFreq){
//                 minFreq = x.second;
//                 minCh = x.first;
//             }
//         }
//         bool once = true, once1 = true;
//         for (auto x : word){
//             if (once && maxCh == x){
//                 once = false;
//                 continue;
//             }
//             m1[x]++;
//         }
//         for (auto x : word){
//             if (once1 && minCh == x){
//                 once1 = false;
//                 continue;
//             }
//             m2[x]++;
//         }
//         for (auto x : m1){
//             maxFreq = x.second;
//             break;
//         }
//         // cout << "max: " << maxFreq << endl;
//         bool maxRemove = true, minRemove = true;
//         for (auto x : m1){
//             // cout << x.first << " " << x.second << endl;
//             if (maxFreq != x.second) maxRemove = false;
//         }
//         // cout << "\n";
//         for (auto x : m2){
//             minFreq = x.second;
//             break;
//         }
//         for (auto x : m2){
//             if (minFreq != x.second) minRemove = false;
//         }
//         if (!maxRemove && !minRemove) return false;
//         return true;
    }
};