func maximumHappinessSum(happiness []int, k int) int64 {
    slices.Sort(happiness)
    total := int64(0)
    n := len(happiness)
    for i := 0; i < len(happiness) && i < k; i++ {
        total += int64(max(0, happiness[n - i - 1] - i))
    }
    return total
}