public class Solution {
    public IList<bool> KidsWithCandies(int[] candies, int extraCandies) {
        var res = new bool[candies.Length];
        int max = 0;
        for (int i = 0; i < candies.Length; i++) {
            if (max < candies[i]) {
                max = candies[i];
            }
        }
        for (int i = 0; i < candies.Length; i++) {
            res[i] = candies[i] + extraCandies >= max;
        }
        return res;
    }
}