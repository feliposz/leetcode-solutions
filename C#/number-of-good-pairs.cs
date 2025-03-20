public class Solution {
    public int NumIdenticalPairs(int[] nums) {
        var count = new Dictionary<int,int>();
        foreach (int n in nums) {
            if (!count.ContainsKey(n)) {
                count[n] = 0;
            }
            count[n]++;
        }
        int result = 0;
        foreach (var (k, v) in count) {
            result += v * (v-1) / 2;
        }
        return result;
    }
}