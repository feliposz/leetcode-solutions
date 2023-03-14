class Solution {
    fun canThreePartsEqualSum(arr: IntArray): Boolean {
        var total = 0
        for (n in arr) {
            total += n
        }
        if (total % 3 != 0) {
            return false
        }
        var target = total / 3
        println("total = $total, target = $target")

        var left = 0
        var i = 0
        do {
            left += arr[i]
            i++
        } while (i < arr.size && left != target);
        println("left = $left, i = $i")

        if (left != target) {
            return false
        }

        var right = 0
        var j = arr.size - 1
        do {
            right += arr[j]
            j--
        } while (j > i && right != target)
        println("right = $right, j = $j")

        if (right != target) {
            return false
        }        

        return i <= j
    }
}