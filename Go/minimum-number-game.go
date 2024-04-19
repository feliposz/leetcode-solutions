func numberGame(nums []int) []int {
    slices.Sort(nums)
    result := make([]int, 0, len(nums))
    for i := 0; i < len(nums); i+=2 {
        result = append(result, nums[i+1], nums[i])
    }
    return result
}