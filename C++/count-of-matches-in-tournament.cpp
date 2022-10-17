class Solution {
public:
    int numberOfMatches(int n) {
        if (n < 2) {
            return 0;
        } else if (n % 2 == 0) {
            return n / 2 + numberOfMatches(n / 2);
        } else {
            return (n - 1) / 2 + numberOfMatches((n - 1) / 2 + 1);
        }
    }
};