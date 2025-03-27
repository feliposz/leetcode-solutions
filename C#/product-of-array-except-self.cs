public class Solution {
    public int[] ProductExceptSelf(int[] nums) {
        var prefix = new int[nums.Length];
        var suffix = new int[nums.Length];
        var res = new int[nums.Length];
        prefix[0] = nums[0];
        suffix[nums.Length-1] = nums[nums.Length-1];
        for (int i = 1; i < nums.Length; i++) {
            prefix[i] = nums[i] * prefix[i-1];
        }
        for (int i = nums.Length - 2; i >= 0; i--) {
            suffix[i] = nums[i] * suffix[i+1];
        }
        for (int i = 0; i < nums.Length; i++) {
            res[i] = 1;
            if (i > 0) {
                res[i] *= prefix[i-1];
            }
            if (i < nums.Length - 1) {
                res[i] *= suffix[i+1];
            }
        }
        return res;
    }
}