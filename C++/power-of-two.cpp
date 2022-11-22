class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n < 1) {
            return false;
        }
        long x = 1;
        while (x <= n) {
            if (n == x) {
                return true;
            }
            x *= 2;
        }
        return false;
    }
};