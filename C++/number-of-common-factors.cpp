class Solution {
public:
    int commonFactors(int a, int b) {
        int factors = 0;
        for (int div = 1; (div <= a) && (div <= b); div++) {
            if ((a % div == 0) && (b % div == 0)) {
                factors++;
            }
        }
        return factors;
    }
};