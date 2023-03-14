class Solution {
    fun repeatedSubstringPattern(s: String): Boolean {
        var n = s.length
        for (parts in 2..n) {
            //println("parts: $parts")
            if (n % parts == 0) {
                var sublen = n / parts
                var pattern = s.substring(0, sublen)
                var valid = true
                //println("sublen: $sublen")
                //println("pattern: $pattern")

                for (x in 1..parts-1) {
                    var pos = x * sublen
                    var sublen = s.substring(pos, pos + sublen)
                    if (pattern != sublen) {
                        valid = false
                        break
                    }
                }
                if (valid) {
                    return true
                }
            }
        }
        return false
    }
}