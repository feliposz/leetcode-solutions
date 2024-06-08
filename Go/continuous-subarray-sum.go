func checkSubarraySum(nums []int, k int) bool {
	modSeen := map[int]int{0: -1}
	prefixMod := 0
	for i, n := range nums {
		prefixMod = (prefixMod + n) % k
		if j, found := modSeen[prefixMod]; found {
			if i-j > 1 {
				return true
			}
		} else {
			modSeen[prefixMod] = i
		}
	}
	return false
}