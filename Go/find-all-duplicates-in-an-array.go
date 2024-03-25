func findDuplicates(nums []int) []int {
    var result []int
    for _, n := range nums {
        if n < 0 {
            n = -n
        }
        if nums[n - 1] < 0 {
            result = append(result, n)
        }
        nums[n-1] = -nums[n-1]
    }
    return result
}

func findDuplicates_nspace(nums []int) []int {
    seen := make(map[int]bool)
    var result []int
    for _, n := range nums {
        if seen[n] {
            result = append(result, n)
        }
        seen[n] = true
    }    
    return result
}

func findDuplicates_nlogn(nums []int) []int {
    slices.Sort(nums)
    var result []int
    for i := 1; i < len(nums); i++ {
        if nums[i-1] == nums[i] {
            result = append(result, nums[i])
        }
    }
    return result
}