class Solution {
public:
    int reverse(int x) {
        int sign = 1;
        if (x == INT32_MIN)
            return 0;
        if (x < 0) {
            x = -x;
            sign = -1;
        }
        long r = 0;
        while (x > 0) {
            r = r * 10 + x % 10;
            x /= 10;
        }
        if (r > INT32_MAX)
            r = 0;
        return sign * r;
    }
};