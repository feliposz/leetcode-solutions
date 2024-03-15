func fourSum(nums []int, target int) [][]int {
    n := len(nums)
    slices.Sort(nums)
    result := make([][]int, 0)
    for a := 0; a < n; a++ {
        if a > 0 && nums[a-1] == nums[a] {
            continue
        }
        for b := a + 1; b < n; b++ {
            if b > a + 1 && nums[b-1] == nums[b] {
                continue
            }
            for c := b + 1; c < n; c++ {
                if c > b + 1 && nums[c-1] == nums[c] {
                    continue
                }
                for d := c + 1; d < n; d++ {
                    if d > c + 1 && nums[d-1] == nums[d] {
                        continue
                    }
                    if nums[a] + nums[b] + nums[c] + nums[d] == target {
                        result = append(result, []int{nums[a], nums[b], nums[c], nums[d]})
                    }
                }
            }
        }
    }
    return result
}