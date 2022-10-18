class Solution {
public:
    bool isPalindrome(int x) {
        int a = x;
        long b = 0;
        while (a > 0) {
            b = b * 10 + a % 10;
            a /= 10;
        }
        return x == b;
    }
};