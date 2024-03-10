func countTriplets(nums []int) int {
    n := len(nums)
    count := 0
    pairs := make([]int, 1<<16)
    for i := 0; i < n; i++ {
        for j := 0; j < n; j++ {
            pairs[nums[i] & nums[j]]++
        }
    }
    for k := 0; k < n; k++ {
        for pair, pairCount := range pairs {
            if nums[k] & pair == 0 {
                count += pairCount
            }
        }
    }
    return count
}