class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        long long powOfTwo = 1;
        
        while (powOfTwo <= left){
            powOfTwo *= 2;
        }
        if (powOfTwo <= right) return 0;
        
        long long int ans = left;
        for (long long int i = left; i <= right; i++) ans &= i;
        return ans;
    }
};

/*

l=5, r=10
5 - 0101
6 - 0110
7 - 0111
8 - 1000
& of power of 2, return 0, so if power of 2 in the range, must return 0


*/