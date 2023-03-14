class Solution {
    fun mergeArrays(nums1: Array<IntArray>, nums2: Array<IntArray>): Array<IntArray> {
        var map = HashMap<Int,Int>()
        for (pair in nums1) {
            map[pair[0]] = pair[1]
        }
        for (pair in nums2) {
            map[pair[0]] = map.getOrElse(pair[0], {0}) + pair[1]
        }
        var ans = Array<IntArray>(map.count()) {i -> IntArray(2)}
        var i = 0
        for ((k, v) in map.toSortedMap()) {
            ans[i][0] = k
            ans[i][1] = v
            i++
        }
        return ans
    }
}