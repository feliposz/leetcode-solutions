class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum = 0;
        for (int div = 1; div < num/2+1; div++) {
            if (num % div == 0) {
                sum += div;
            }
        }
        return sum == num;
    }
};