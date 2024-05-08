func findRelativeRanks(score []int) []string {
    scorePos := map[int]int{}
    for pos, x := range score {
        scorePos[x] = pos
    }
    slices.Sort(score)
    result := make([]string, len(score))
    for i, x := range score {
        rank := ""
        switch len(score) - i {
        case 1:
            rank = "Gold Medal"
        case 2:
            rank = "Silver Medal"
        case 3:
            rank = "Bronze Medal"
        default:
            rank = fmt.Sprint(len(score) - i)
        }
        result[scorePos[x]] = rank
    }
    return result
}