func findKDistantIndices(nums []int, key int, k int) []int {
    result := make([]int, 0, len(nums))
    last_key := -1
    for i := range nums {
        // only need to check around k distance
        start, end := max(0, i - k), min(i + k, len(nums) - 1)
        // if the last found key is around the same range, no need to search again for another
        if last_key >= start && last_key <= end {
            result = append(result, i)
        } else {
            // look for the key on the range
            for j := start; j <= end; j++ {
                if nums[j] == key {
                    result = append(result, i)
                    last_key = j
                    break
                }
            }
        }
    }
    // since indices were added in order, there is no need to sort
    return result
}