func subarraysDivByK(nums []int, k int) int {
    count := 0
    sum := 0
    seen := make([]int, k)
    seen[0] = 1
    for _, n := range nums {
        sum = (sum + n % k + k) % k
        count += seen[sum]
        seen[sum]++
    }
    return count
}