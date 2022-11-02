class Solution {
public:
    int countEven(int num) {
        int count = 0;
        for (int i = 1; i <= num; i++) {
            int sum = digitSum(i);
            if (sum % 2 == 0) {
                count++;
            }
        }
        return count;
    }
    
    int digitSum(int x) {
        int sum = 0;
        while (x) {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }
};