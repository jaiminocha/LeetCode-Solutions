class Solution {
public:
    int solve(string &s, int i, int j, vector<vector<int> > &memo){
        // base case
        if (i > j) return 0;
        
        if (memo[i][j] != -1) return memo[i][j];
        
        // include
        if (s[i] == s[j]) return memo[i][j] = ((i == j ? 1 : 2) + solve(s, i + 1, j - 1, memo));
        
        int op2 = solve(s, i, j - 1, memo);
        int op1 = solve(s, i + 1, j, memo);
        
        return memo[i][j] = max(op1, op2);
    }
    int minInsertions(string s) {
//         int i = 0, j = s.length() - 1;
//         int ans = 0;
        
//         while (i < j){
//             if (s[i] == s[j]){
//                 i++; j--;
//                 continue;
//             }
//             else {
//                 ans++;
//                 i++;
//             }
//         }
        
//         return ans;
        
        int n = s.size();
        // if (n < 2) return 1;
        vector<vector<int> > memo(n + 1, vector<int> (n + 1, -1));
        int ans = solve(s, 0, n - 1, memo);
//         for (auto x : memo) {
//             for(auto y : x) {
//                 cout << y << " ";}
//             cout << "\n";}
        
        return n - ans;
    }
};