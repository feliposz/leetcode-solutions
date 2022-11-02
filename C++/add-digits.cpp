class Solution {
public:
    int addDigits(int num) {
        while (num >= 10) {
            num = sumDigits(num);
        }
        return num;
    }
    
    int sumDigits(int x) {
        int sum = 0;
        while (x) {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }
};