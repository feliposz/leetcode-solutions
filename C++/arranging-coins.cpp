class Solution {
public:
    int arrangeCoins(int n) {
        int lo = 0, hi = n;
        while (lo <= hi) {
            long mid = (lo + hi) / 2;
            long q = mid * (mid + 1) / 2;
            if (n == q) {
                return mid;
            } else if (n > q) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return hi;
    }
};