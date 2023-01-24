/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long i = 1, j = n;
        while (true) {
            long g = (i + j) / 2;
            int r = guess(g);
            if (r == 0) {
                return g;
            } else if (r < 0) {
                j = g - 1;
            } else {
                i = g + 1;
            }
        }
        return -1;
    }
};