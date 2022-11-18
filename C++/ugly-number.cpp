class Solution {
public:
    bool isUgly(int n) {
        for (int div = 5; div > 1; div--) {
            while (n > 1 && n % div == 0) {
                n /= div;
            }            
        }
        return n == 1;
    }
};