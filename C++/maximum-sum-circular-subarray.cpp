class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int cur_max = 0, cur_min = 0, min_sum = nums[0], max_sum = nums[0], sum = 0;
        for (int i : nums) {
            cur_max = max(cur_max, 0) + i;
            max_sum = max(cur_max, max_sum);
            cur_min = min(cur_min, 0) + i;
            min_sum = min(cur_min, min_sum);
            sum += i;
        }
        return sum == min_sum ? max_sum : max(max_sum, sum - min_sum);
    }
};