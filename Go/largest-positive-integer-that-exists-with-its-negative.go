func findMaxK(nums []int) int {
    slices.Sort(nums)
    left, right := 0, len(nums) - 1
    for left < right {
        if -nums[left] == nums[right] {
            return nums[right]
        } else if -nums[left] < nums[right] {
            right--
        } else {
            left++
        }
    }
    return -1
}