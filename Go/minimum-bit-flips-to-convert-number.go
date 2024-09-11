func minBitFlips(start int, goal int) int {
	x := start ^ goal
	bits := 0
	for x != 0 {
		if x&1 != 0 {
			bits++
		}
		x >>= 1
	}
	return bits
}