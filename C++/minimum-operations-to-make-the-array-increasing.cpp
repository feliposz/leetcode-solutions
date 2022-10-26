class Solution {
public:
    int minOperations(vector<int>& nums) {
        int sz = nums.size();
        int ops = 0;
        for (int i = 1; i < sz; i++) {
            if (nums[i-1] >= nums[i]) {
                ops += (nums[i-1] - nums[i]) + 1;
                nums[i] = nums[i-1] + 1;
            }
        }
        return ops;
    }
};