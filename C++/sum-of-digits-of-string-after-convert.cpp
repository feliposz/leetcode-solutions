class Solution {
public:
    int getLucky(string s, int k) {
        int sum = 0;
        for (auto c : s) {
            int value = c - 'a' + 1;
            sum += value % 10 + value / 10;
        }
        while (k > 1) {
            int newSum = 0;
            while (sum > 0) {
                newSum += sum % 10;
                sum /= 10;
            }
            sum = newSum;
            k--;
        }
        return sum;
    }
};