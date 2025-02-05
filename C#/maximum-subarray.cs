public class Solution {
    public int MaxSubArray(int[] nums) {
        int acc = 0, max = nums[0];
        acc = nums[0];
        for (int i = 1; i < nums.Length; i++) {
            acc = Math.Max(nums[i], nums[i] + acc);
            max = Math.Max(acc, max);
        }
        return max;
    }
}