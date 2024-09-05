func missingRolls(rolls []int, mean int, n int) []int {
    m := len(rolls)
    mSum := 0
    for _, x := range rolls {
        mSum += x
    }
    count := m + n
    sum := mean * count
    nSum := sum - mSum
    //fmt.Println(count, sum, mSum, nSum)
    if nSum < n || nSum > n * 6 {
        return nil
    }
    nMean := nSum / n
    diff := nSum - nMean * n
    result := make([]int, n)    
    for i := range result {
        result[i] = nMean
        if diff > 0 {
            result[i]++
            diff--
        }
    }
    return result
}