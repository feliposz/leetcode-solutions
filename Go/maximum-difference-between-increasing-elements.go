func maximumDifference(nums []int) int {
    n := len(nums)
    maxDiff := -1
    for i := 0; i < n; i++ {
        for j := i + 1; j < n; j++ {
            if nums[i] < nums[j] {
                diff := nums[j] - nums[i]
                maxDiff = max(maxDiff, diff)
            }
        }
    }
    return maxDiff
}