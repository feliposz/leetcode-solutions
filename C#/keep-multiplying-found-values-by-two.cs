public class Solution {
    public int FindFinalValue(int[] nums, int original) {
        var data = new HashSet<int>(nums);
        int count = 0;
        while (true) {
            if (data.Contains(original)) {
                original *= 2;
            } else {
                break;
            }
        }
        return original;
    }
}