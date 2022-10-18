//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(vector<vector<int> > &mine, int n, int m, int row, int col, vector<vector<int> > &dp){
        if (col == m){
            return 0;
        }
        
        if (dp[row][col] != -1) return dp[row][col];
        
        int op1 = 0, op2 = 0, op3  = 0;
        if (row + 1 < n){
            op1 = mine[row][col] + solve(mine, n, m, row + 1, col + 1, dp);
        }
        if (row - 1 >= 0){
            op2 = mine[row][col] + solve(mine, n, m, row - 1, col + 1, dp);
        }
        op3 = mine[row][col] + solve(mine, n, m, row, col + 1, dp);
        
        return dp[row][col] = max(op1, max(op2, op3));
    }
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        int ans = 0;
        for (int i = 0; i < n; i++){
            vector<vector<int> > dp(51, vector<int> (51, -1));
            ans = max(ans, solve(M, n, m, i, 0, dp));
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends