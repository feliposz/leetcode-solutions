public class Solution {
    public int CountDigits(int num) {
        int tmp = num;
        int count = 0;
        while (tmp > 0) {
            int div = tmp % 10;
            if (num % div == 0) {
                count++;
            }
            tmp /= 10;
        }
        return count;
    }
}