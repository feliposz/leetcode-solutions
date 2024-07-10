func removeDuplicates(nums []int) int {
    j := 0
    for i := 1; i < len(nums); i++ {
        if nums[i] != nums[j] {
            j++
            nums[j] = nums[i]
        }
    }
    nums = nums[:j + 1]
    return len(nums)
}