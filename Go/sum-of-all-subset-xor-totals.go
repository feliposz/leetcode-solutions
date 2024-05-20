func subsetXORSum(nums []int) int {
    return sum(nums, 0)
}

func sum(nums []int, current int) int {
    if len(nums) == 0 {
        return current
    }
    return sum(nums[1:], current ^ nums[0]) + sum(nums[1:], current)
}