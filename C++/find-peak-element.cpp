class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int sz = nums.size();
        if (sz == 1) {
            return 0;
        } else if (sz == 2) {
            return nums[0] > nums[1] ? 0 : 1;
        }
        for (int i = 0; i < sz; i++) {
            if (i == 0) {
                if (nums[0] > nums[1]) {
                    return i;
                }
            } else if (i == sz - 1) {
                if (nums[sz - 1] > nums[sz - 2]) {
                    return i;
                }
            } else if (nums[i-1] < nums[i] && nums[i] > nums[i+1]) {
                return i;
            }
        }
        return 0;
    }
};