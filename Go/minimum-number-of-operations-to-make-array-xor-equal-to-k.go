func minOperations(nums []int, k int) int {
    all := k
    for _, n := range nums {
        all ^= n
    }
    count := 0
    for all > 0 {
        count += all & 1
        all >>= 1
    }
    return count
}