func countPairs(nums []int, target int) int {
    slices.Sort(nums)
    count := 0
    left := 0
    right := len(nums) - 1
    for left < right {
        sum := nums[left] + nums[right]
        if sum < target {
            count += right - left
            left++
        } else {
            right--
        }
    }
    return count
}