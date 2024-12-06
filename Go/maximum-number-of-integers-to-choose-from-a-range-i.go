func maxCount(banned []int, n int, maxSum int) int {
	sum := 0
	slices.Sort(banned)
	// fmt.Println(banned)
	i := 0
	count := 0
	for x := 1; x <= n; x++ {
		if i < len(banned) && banned[i] == x {
			for i < len(banned) && banned[i] == x {
				i++
			}
			continue
		}
		sum += x
		if sum > maxSum {
			break
		}
		count++
	}
	// fmt.Println(sum)
	return count
}