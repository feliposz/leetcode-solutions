class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int sz = nums.size();

        int count = 0;

        for (int i = 0; i < sz; i++) {
            for (int j = i + 2; j < sz; j++) {
                if ((nums[j] - nums[j-1]) == (nums[j-1] - nums[j-2])) {
                    count++;
                } else {
                    break;
                }
            }
        }
        return count;
    }
};