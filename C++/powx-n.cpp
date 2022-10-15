class Solution {
public:
    double myPow(double x, int n) {        
        if (x == 0) {
            return 0;
        }

        if (x == 1) {
            return 1;
        }

        if (n < 0) {
            if (n == INT32_MIN) {
                n = INT32_MAX;
                x = 1 / x / x;
            } else {
                n = -n;
                x = 1 / x;
            }            
        }
               
        double result = 1;
        double base = x;
        
        while (n > 0) {
            if (n % 2 == 0) {
                n /= 2;
                base *= base;
            } else {
                n--;
                result *= base;    
                n /= 2;
                base *= base;
            }            
        }
        
        return result;
    }
};