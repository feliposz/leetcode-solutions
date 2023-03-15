class Solution {
    fun addBinary(a: String, b: String): String {
        var ra = a.reversed()
        var rb = b.reversed()
        var carry = 0
        var i = 0
        var rc = StringBuilder()
        while (i < ra.length || i < rb.length) {
            var x = carry;
            if (i < ra.length) {
                x += ra[i] - '0';
            }
            if (i < rb.length) {
                x += rb[i] - '0';
            }
            rc.append(if (x % 2 == 0) '0' else '1');
            i++;
            carry = x / 2;
        }
        if (carry > 0) {
            rc.append(if (carry == 0) '0' else '1');
        }
        return rc.toString().reversed();
    }
}