func firstMissingPositive(nums []int) int {
    n := len(nums)

    // cycle sort values to their expected position
    for i := 0; i < n; {
        expectedIndex := nums[i] - 1
        if nums[i] > 0 && nums[i] <= n && nums[i] != nums[expectedIndex] {
            nums[i], nums[expectedIndex] = nums[expectedIndex], nums[i]
        } else {
            i++
        }
    }

    // find the first number that is not in the right position
    for i := 0; i < n; i++ {
        if nums[i] != i + 1 {
            return i + 1
        }
    }

    // all numbers from 1 to n are in their correct position, so return the next one
    return n + 1
}