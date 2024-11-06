func canSortArray(nums []int) bool {
	prevMax, currMin, currMax := -1, nums[0], nums[0]
	currBits := countSetBits(nums[0])
	for _, x := range nums {
		if currBits == countSetBits(x) {
			currMin = min(currMin, x)
			currMax = max(currMax, x)
		} else {
			if currMin < prevMax {
				return false
			}
			prevMax = currMax
			currMin, currMax = x, x
			currBits = countSetBits(x)
		}
	}
	if currMin < prevMax {
		return false
	}
	return true
}

func countSetBits(x int) int {
	bits := 0
	for x > 0 {
		bits += int(x & 1)
		x >>= 1
	}
	return bits
}