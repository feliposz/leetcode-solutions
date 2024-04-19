func sumOfSquares(nums []int) int {
    sum := 0
    for i, x := range nums {
        if len(nums) % (i + 1) == 0 {
            sum += x * x
        }
    }
    return sum
}