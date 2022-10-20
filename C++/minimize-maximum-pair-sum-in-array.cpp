class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int maxSum = INT32_MIN;
        for (int i = 0, j = nums.size() - 1; i < j; i++, j--) {
            int sum = nums[i] + nums[j];
            if (maxSum < sum) {
                maxSum = sum;
            }
        }
        return maxSum;
    }
};