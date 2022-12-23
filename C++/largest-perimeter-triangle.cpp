class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int maxPer = 0;
        int sz = nums.size();
        for (int i = sz - 1; i > 1; i--) {
            if (((nums[i-2] + nums[i-1]) > nums[i])) {
                int per = nums[i] + nums[i-1] + nums[i-2];
                if (per > maxPer) {
                    maxPer = per;
                }
            }                        
        }
        return maxPer;
    }
};