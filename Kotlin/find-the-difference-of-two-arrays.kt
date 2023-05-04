class Solution {
    fun findDifference(nums1: IntArray, nums2: IntArray): List<List<Int>> {
        val set1 = nums1.toSet()
        val set2 = nums2.toSet()

        val a = set1 - set2
        val b = set2 - set1

        return listOf(a.toList(), b.toList())
    }
}