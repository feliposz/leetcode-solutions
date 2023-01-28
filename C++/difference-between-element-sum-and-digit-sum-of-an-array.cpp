class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        long sum = 0, digitSum = 0;
        for (int num : nums) {
            sum += num;
            while (num > 0) {
                digitSum += num % 10;
                num /= 10;
            }
        }
        return abs(sum - digitSum);
    }
};