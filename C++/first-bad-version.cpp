// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int i = 1, j = n;
        int firstBad = -1;
        while (i <= j) {
            int k = (int)(((long)i + j) / 2);
            if (isBadVersion(k)) {
                firstBad = k;
                j = k - 1;
            } else {
                i = k + 1;
            }
        }
        return firstBad;
    }
};