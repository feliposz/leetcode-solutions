class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int sz = nums.size();
        if (sz < 2) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int maxDiff = INT32_MIN;
        for (int i = 1; i < sz; i++) {
            int diff = abs(nums[i-1] - nums[i]);
            if (maxDiff < diff) {
                maxDiff = diff;
            }
        }
        return maxDiff;
    }
};