func subsets(nums []int) [][]int {
    result := [][]int{}
    genSubsets(nums, []int{}, &result)
    return result
}

func genSubsets(nums []int, curr []int, result *[][]int) {
    if len(nums) == 0 {
        *result = append(*result, curr)
        return
    }
    genSubsets(nums[1:], curr, result)
    genSubsets(nums[1:], append(slices.Clone(curr), nums[0]), result)
}