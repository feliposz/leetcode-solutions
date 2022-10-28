class Solution {
public:
    int trailingZeroes(int n) {
        int fives = 0;
        for (int i = 1; i <= n; i++) {
            if (i % 5 == 0) {
                fives++;
            }
            if (i % 25 == 0) {
                fives++;
            }
            if (i % 125 == 0) {
                fives++;
            }
            if (i % 625 == 0) {
                fives++;
            }
            if (i % 3125 == 0) {
                fives++;
            }
        }
        return fives;
    }
};