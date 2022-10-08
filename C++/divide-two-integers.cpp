class Solution {
public:
    
    int divide(int dividend, int divisor) {
        long result = divide64(dividend, divisor);

        if (result < INT32_MIN)
            return INT32_MIN;
        if (result > INT32_MAX)
            return INT32_MAX;
        return (int)result;
    }
    
    long divide64(long dividend, long divisor) {
        long sign = 1;
        
        if (dividend < 0) {
            dividend = -dividend;
            sign = -sign;
        }
        
        if (divisor < 0) {
            divisor = -divisor;
            sign = -sign;
        }
        
        if (divisor > dividend) {
            return 0;
        }

        while (divisor > INT16_MAX) {
            dividend >>= 1;
            divisor >>= 1;
        }

        long quotient = 0;

        if (divisor == 1) {
            quotient = dividend;
        } else {
            while (dividend >= divisor) {
                dividend -= divisor;
                quotient++;
            }
        }

        return sign * quotient;        
    }
};