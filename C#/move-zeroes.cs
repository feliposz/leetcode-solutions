public class Solution {
    public void MoveZeroes(int[] nums) {
        int dest = 0;
        for (int i = 0; i < nums.Length; i++) {
            if (nums[i] != 0) {
                nums[dest++] = nums[i];
            }
        }
        while (dest < nums.Length) {
            nums[dest++] = 0;
        }
    }
}