class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int count = 0;
        set<int> primes({2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31});
        for (int n = left; n <= right; n++) {
            int bits = countBits(n);
            if (primes.count(bits)) {
                count++;
            }
        }
        return count;
    }
    
    int countBits(int n) {
        int count = 0;
        while (n) {
            if (n & 1) {
                count++;
            }
            n >>= 1;
        }
        return count;
    }
};