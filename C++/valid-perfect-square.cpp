class Solution {
public:
    bool isPerfectSquare(int num) {
        long x = 1;
        for (int i = 1; x <= num; i++) {
            x = (long)i * i;
            if (x == num) {
                return true;
            }
        }
        return false;
    }
};