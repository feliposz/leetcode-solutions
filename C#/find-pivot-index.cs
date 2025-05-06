public class Solution {
    public int PivotIndex(int[] nums) {
        int right = 0;
        int left = 0;
        for (int i = 0; i < nums.Length; i++) {
            right += nums[i];
        }
        for (int i = 0; i < nums.Length; i++)
        {
            right -= nums[i];
            if (left == right) {
                return i;
            }
            left += nums[i];
        }
        return -1;
    }
}