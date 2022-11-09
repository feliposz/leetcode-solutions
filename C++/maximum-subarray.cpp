class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sz = nums.size();
        vector<int> dp(sz);
        dp[0] = nums[0];
        for (int i = 1; i < sz; i++) {
            dp[i] = max(nums[i], nums[i] + dp[i-1]);
        }
        return *max_element(dp.begin(), dp.end());
    }
};