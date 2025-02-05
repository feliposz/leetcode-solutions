public class Solution {
    public int MaxAscendingSum(int[] nums) {
        int curr = nums[0];
        int max = curr;
        for (int i = 1; i < nums.Length; i++) {
            if (nums[i-1] >= nums[i]) {
                curr = 0;
            }
            curr += nums[i];
            if (max < curr) {
                max = curr;
            }
        }
        return max;
    }
}