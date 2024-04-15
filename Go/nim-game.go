func canWinNim(n int) bool {
	return n & 3 != 0 // (same as n % 4)
}