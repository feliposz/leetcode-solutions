class Solution {
    fun predictPartyVictory(senate: String): String {
        val s = senate.toCharArray()
        while (true) {
            for (i in 0 until s.size) {
                val team = s[i]
                if (team == ' ') {
                    continue
                }
                val other = if (team == 'R') 'D' else 'R'
                var winner = true
                for (j in 1 until s.size - 1) {
                    val k = (i + j) % s.size
                    if (s[k] == other) {
                        s[k] = ' '
                        winner = false
                        break
                    }
                }
                if (winner) {
                    return if (team == 'R') "Radiant" else "Dire"
                }
            }
        }
        return "None"
    }
}