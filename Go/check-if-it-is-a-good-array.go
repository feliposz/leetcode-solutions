func isGoodArray(nums []int) bool {
	x := nums[0]
    for _, y := range nums {
        x = gcd(x, y)
        if x == 1 {
            return true
        }
	}
	return false
}

func gcd(a, b int) int {
    if b == 0 {
        return a
    }
    return gcd(b, a % b)
}