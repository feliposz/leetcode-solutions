func findComplement(num int) int {
	ans := 0
	for shift := 0; num > 0; shift++ {
		ans |= (1 ^ (num & 1)) << shift
		num >>= 1
	}
	return ans
}