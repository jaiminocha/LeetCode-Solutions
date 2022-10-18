//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int solve(int coins[], int n, int i, int target, vector<vector<long long int> > &dp){
        if (i == n){
            if (target == 0) return 1;
            return 0;
        }
        if (dp[i][target] != -1){
            return dp[i][target];
        }
        long long int op1 = solve(coins, n, i + 1, target, dp);
        long long int op2 = 0;
        if (target - coins[i] >= 0){
            op2 += solve(coins, n, i, target - coins[i], dp);
        }
        return dp[i][target] = op1 + op2;
    }
    long long int count(int coins[], int N, int sum) {
        // code here.
        vector<vector<long long int> > dp(1001, vector<long long int> (1001, -1));
        return solve(coins, N, 0, sum, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends