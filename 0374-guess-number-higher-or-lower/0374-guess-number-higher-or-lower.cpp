/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int s = 1, e = n;
        int mid = -1;
        while (s <= e){
            mid = s + (e - s)/2;
            int val = guess(mid);
            if (val == 0){
                break;
            }
            else if (val == 1){
                s = mid + 1;
            }
            else {
                e = mid - 1;
            }
        }
        return mid;
    }
};