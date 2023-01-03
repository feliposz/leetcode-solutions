public class Solution {
    public int MinimumOperations(int[] nums) {
        Array.Sort(nums);
        int count = 0;
        for (int i = 0; i < nums.Length; i++) {
            if (nums[i] > 0) {
                count++;
                int x = nums[i];
                for (int j = i; j < nums.Length; j++) {
                    nums[j] = Math.Max(nums[j] - x, 0);
                }
            }
        }
        return count;
    }
}