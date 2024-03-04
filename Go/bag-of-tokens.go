func bagOfTokensScore(tokens []int, power int) int {
    slices.Sort(tokens)
    points := 0
    maxPoints := 0
    buy := 0
    sell := len(tokens) - 1
    for buy <= sell {
        if tokens[buy] <= power {
            power -= tokens[buy]
            buy++
            points++            
            if maxPoints < points {
                maxPoints = points
            }
        } else if points > 0 {
            power += tokens[sell]
            sell--
            points--
        } else {
            break
        }
    }
    return maxPoints
}