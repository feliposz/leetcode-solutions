class Solution {
public:
    bool judgeSquareSum(int c) {
        set<int> sq;
        for (int n = 0; ; n++) {
            long n2 = (long)n * n;
            if (n2 > c) {
                break;
            }
            sq.insert(n2);
        }
        for (int s : sq) {
            int t = c - s;
            if (t < 0) {
                break;
            }
            if (sq.count(t)) {
                return true;
            }
        }
        return false;
    }
};