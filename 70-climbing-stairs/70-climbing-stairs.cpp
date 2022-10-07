class Solution {
public:
    // Was giving TLE without DP    
    int climbStairs(int n) {
        // if (n < 2) {
        //     return 1;
        // }
        // return climbStairs(n-1) + climbStairs(n-2);
        // int* a = new int[n]{-1};
        vector<int> a(n + 1, -1);
        return helper(n, a);
    }
    
    int helper(int n, vector<int>& a){
       if (n < 2) {
            return 1;
        }
        if (a[n] != -1){
            return a[n];
        }
        return a[n] = helper(n-1, a) + helper(n-2, a); 
    }
};