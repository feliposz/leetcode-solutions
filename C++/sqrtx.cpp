class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;
        int lo = 1, hi = x;
        while (lo <= hi) {
            long mid = ((long)lo + hi) / 2;
            long guess = mid * mid;
            if (guess == x) {
                return mid;
            } else if (guess > x) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return lo - 1;
    }
};