class Solution {
    fun kidsWithCandies(candies: IntArray, extraCandies: Int): List<Boolean> {
        val maxCandies = candies.max()!!
        val ans = mutableListOf<Boolean>()
        for (c in candies) {
            ans.add((c + extraCandies) >= maxCandies)
        }
        return ans
    }
}