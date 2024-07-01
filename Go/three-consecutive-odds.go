func threeConsecutiveOdds(arr []int) bool {
    odds := 0
    for _, n := range arr {
        if n & 1 != 0 {
            odds++
            if odds == 3 {
                return true
            }
        } else {
            odds = 0
        }
    }
    return false
}