public class Solution {
    public bool IncreasingTriplet(int[] nums) {
        int a = int.MaxValue, b = int.MaxValue;
        foreach (int n in nums) {
            if (n <= a) {
                a = n;
            } else if (n <= b) {
                b = n;
            } else {
                return true;
            }
        }
        return false;
    }
}