class Solution {
public:
    int subtractProductAndSum(int n) {
        int prod = 1;
        int sum = 0;
        while (n) {
            int digit = n % 10;
            prod *= digit;
            sum += digit;
            n /= 10;
        }
        return prod - sum;
    }
};