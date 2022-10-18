class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sz = nums.size();
        int len = 1;
        int maxLen = 0;
        for (int i = 1; i < sz; i++) {
            if (nums[i-1] + 1 == nums[i]) {
                len++;
            } else if (nums[i-1] == nums[i]) {
                /* skip */
            } else {
                len = 1;
            }
            if (len > maxLen) {
                maxLen = len;
            }
        }
        if (sz == 1) {
            return 1;
        }
        return maxLen;
    }
};