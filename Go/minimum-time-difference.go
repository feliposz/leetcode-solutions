func findMinDifference(timePoints []string) int {
	tps := make([]int, len(timePoints))
	for i, tp := range timePoints {
		parts := strings.Split(tp, ":")
		h, _ := strconv.Atoi(parts[0])
		m, _ := strconv.Atoi(parts[1])
		tps[i] = h*60 + m
	}
	slices.Sort(tps)
	minDiff := 1000000
	for i := 0; i < len(tps); i++ {
		var diff int
		if i == 0 {
			diff = tps[len(tps)-1] - tps[i]
		} else {
			diff = tps[i] - tps[i-1]
		}
		if diff > 720 {
			diff = 1440 - diff
		}
		minDiff = min(minDiff, diff)
	}
	return minDiff
}