func smallestDistancePair(nums []int, k int) int {
	maxNum := 0
	for _, x := range nums {
		maxNum = max(maxNum, x)
	}
	dists := make([]int, maxNum+1)
	for j, y := range nums {
		for _, x := range nums[:j] {
			dist := abs(x - y)
			dists[dist]++
		}
	}
	count := 0
	for n, q := range dists {
		count += q
		if count >= k {
			return n
		}
	}
	return -1
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}