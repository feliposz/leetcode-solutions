func uniqueOccurrences(arr []int) bool {
    count := map[int]int{}
    for _, n := range arr {
        count[n]++
    }
    seen := map[int]bool{}
    for _, n := range count {
        if seen[n] {
            return false
        }
        seen[n] = true
    }
    return true
}