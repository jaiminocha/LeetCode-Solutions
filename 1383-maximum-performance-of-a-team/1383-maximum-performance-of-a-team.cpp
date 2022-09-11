const int mod = 1e9 + 7;
class Solution {
//     int solve(vector<int> &speed, vector<int> &eff, int i, int k, int count, int sumSpeed, int minEff = INT_MAX){
//         if (i == speed.size() || count == k){
//             if (minEff != INT_MAX){
//                 int maxP = ((sumSpeed % mod) * (minEff % mod)) % mod;
//                 return maxP;
//             }
//             return 0;
//         }
        
//         // inclusion
//         int perf1 = solve(speed, eff, i + 1, k, count + 1, (sumSpeed + speed[i]) % mod, min(minEff, eff[i]));
//         // exclusion
//         int perf2 = solve(speed, eff, i + 1, k, count, sumSpeed, minEff);
        
//         return max(perf1, perf2);
//     }
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        
        // return solve(speed, efficiency, 0, k, 0, 0);
        
        // speed, eff
        priority_queue<int, vector<int>, greater<int> > pq;
        vector<pair<int, int> > eff(n);
        for (int i = 0; i < n; i++){
            eff.push_back({efficiency[i], speed[i]});
        }
        sort(eff.rbegin(), eff.rend());
        
        long long int teamSpeed = 0, maxP = 0;
        for (auto engg : eff){
            if (pq.size() == k){
                teamSpeed -= pq.top();
                pq.pop();
            }
            pq.push(engg.second);
            teamSpeed += engg.second;
            maxP = max(maxP, ((teamSpeed * engg.first)));
        }
        return (int)(maxP % mod);
    }
};