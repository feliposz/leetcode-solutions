class Solution {
    fun nextGreaterElement(n: Int): Int {
        var digits = n.toString().toCharArray()
        
        // check for increasing pattern from right to left
        var i = digits.size - 1
        while (i-1 >= 0 && digits[i] <= digits[i-1]) {
            i -= 1
        }

        // if reached the end, its already at last permutation
        if (i == 0) {
            return -1
        }

        // find next greater value to swap
        var j = i
        while (j + 1 < digits.size && digits[j+1] > digits[i-1]) {
            j += 1
        }

        //println("i = $i, j = $j, digits = ${digits.joinToString()}")
            
        // swap digits
        digits[i-1] = digits[j].also { digits[j] = digits[i-1] }

        //println("swapped digits = ${digits.joinToString()}")

        digits.sort(i)

        //println("sorted digits = ${digits.joinToString()}")        

        val tmp = digits.joinToString(separator="").toLong()

        if (tmp > Int.MAX_VALUE) {
            return -1
        }

        return tmp.toInt()
    }
}