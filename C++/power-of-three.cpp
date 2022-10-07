class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        
        long x = 1;
        while (x <= n) {
            if (x == n)
                return true;
            x *= 3;
        }
        return false;
    }
};