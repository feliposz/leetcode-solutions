func sumIndicesWithKSetBits(nums []int, k int) int {
    sum := 0
    for i, n := range nums {
        if countBits(i) == k {
            sum += n
        }
    }
    return sum
}

func countBits(x int) int {
    count := 0
    for x != 0 {
        if x & 1 == 1 {
            count++
        }
        x >>=1
    }
    return count
}