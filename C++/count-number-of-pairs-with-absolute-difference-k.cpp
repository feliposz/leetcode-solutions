class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int sz = nums.size();
        int count = 0;
        for (int i = 0; i < sz; i++) {
            for (int j = i + 1; j < sz; j++) {
                if (abs(nums[i] - nums[j]) == k) {
                    count++;
                }
            }
        }
        return count;
    }
};