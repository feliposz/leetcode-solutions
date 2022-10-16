class Solution {
public:
    int balancedStringSplit(string s) {
        int count = 0;
        int r = 0;
        int l = 0;
        for (char c: s) {
            if (c == 'L') {
                l++;
            } else if (c == 'R') {
                r++;
            }
            if (l == r) {
                count++;
                r = 0;
                l = 0;
            }
        }
        return count;
    }
};