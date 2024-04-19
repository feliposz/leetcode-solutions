func minOperations(nums []int, k int) int {
    ops := 0
    for _, n := range nums {
        if n < k {
            ops++
        }
    }
    return ops
}