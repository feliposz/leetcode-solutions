class Solution {
public:
    vector<int> memo;
    
    
    int rob(vector<int>& nums) {
        int sz = nums.size();
        memo.resize(sz);
        for (int i = 0; i < sz; i++) {
            memo[i] = INT32_MIN;
        }
        return partial(nums, 0, sz);
    }
    
    int partial(vector<int>& nums, int i, int sz) {
        int result = 0;
        if (i < sz) {
            if (memo[i] != INT32_MIN) {
                result = memo[i];
            } else {
                int a = nums[i] + partial(nums, i + 2, sz);
                int b = partial(nums, i + 1, sz);
                result = a > b ? a : b;
            }
            memo[i] = result;
        }
        return result;
    }
};