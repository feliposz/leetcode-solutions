class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int result = left & right;
        if (right - left < 1000) {
            for (long i = left; i <= right; i++) {
                result &= i;
            }
        } else {
            for (long i = 1; i <= INT_MAX; i <<= 1) {
                if (i >= left && i <= right) {
                    result &= i;
                }
            }
        }
        return result;
    }
};