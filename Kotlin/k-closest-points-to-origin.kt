class Solution {
    fun kClosest(points: Array<IntArray>, k: Int): Array<IntArray> {
        points.sortWith(Comparator {
            a: IntArray, b: IntArray -> lengthSq(a) - lengthSq(b)
        })
        /*
        for (p in points) {
            val d= lengthSq(p)
            print("[${p[0]}, ${p[1]} | d=$d], ")
        }
        */
        val tmp = points.take(k)
        val result = Array<IntArray>(k) {i -> tmp[i]}
        return result
    }

    fun lengthSq(p: IntArray): Int {
        return p[0]*p[0] + p[1]*p[1]
    }
}