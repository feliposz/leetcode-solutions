func numSubarraysWithSum(nums []int, goal int) int {
    count, sum := 0, 0
    freq := make(map[int]int)
    for _, n := range nums {
        sum += n
        if sum == goal {
            count++
        }
        count += freq[sum - goal]
        freq[sum]++
    }
    return count
}