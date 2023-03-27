class Solution {
    fun lemonadeChange(bills: IntArray): Boolean {
        val cashRegister = mutableMapOf<Int,Int>()
        
        for (payment in bills) {
            cashRegister[payment] = cashRegister.getOrElse(payment, {0}) + 1
            if (payment > 5) {
                var change = payment - 5
                for (k in cashRegister.keys.sortedDescending()) {
                    while (cashRegister.getValue(k) > 0 && change >= k) {
                        change -= k
                        cashRegister[k] = cashRegister.getValue(k) - 1
                    }
                }
                if (change != 0) {
                    return false
                }
            }
        }

        return true
    }
}