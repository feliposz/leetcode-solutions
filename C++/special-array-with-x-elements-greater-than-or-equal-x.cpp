class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int lo = 0, hi = n - 1;
        while (lo <= hi) {
            int i = (lo + hi) / 2;
            int x = n - i;
            if (nums[i] >= x) {
                if (i == 0 || nums[i-1] < x) {
                    return x;
                } else {
                    hi = i - 1;
                }
            } else {
                lo = i + 1;
            }
        }
        return -1;
    }
};