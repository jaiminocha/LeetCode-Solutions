// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
    
public:
    int rand10() {
        int x1, x2;
        
        x1 = rand7();
        x2 = rand7();
        while (x2 == 7){
            x2 = rand7();
        }
        while (x1 == 6 || x1 == 7){
            x1 = rand7();
        }
        return x2 > 3 ? x1 + 5 : x1;
    }
};