class Solution {
    fun isWinner(player1: IntArray, player2: IntArray): Int {
        val score1 = calcScore(player1)
        val score2 = calcScore(player2)
        if (score1 > score2) {
            return 1
        } else if (score1 < score2) {
            return 2
        } else {
            return 0
        }
    }
    
    fun calcScore(player: IntArray): Int {
        var score = 0
        for (i in 0 until player.size) {
            var mult = 1
            if (i > 0 && player[i-1] == 10)
                mult = 2
            if (i > 1 && player[i-2] == 10)
                mult = 2
            score += mult * player[i]
        }
        return score
    }
}