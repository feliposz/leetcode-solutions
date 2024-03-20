func maxTwoEvents(events [][]int) int {
    cmpEvent := func(a, b []int) int {
		if a[0] != b[0] {
			return a[0] - b[0]
		}
		return a[1] - b[1]
	}
    
    // sort events by starting time, to make it possible to do a binary search below
	slices.SortFunc(events, cmpEvent)

    // fill this "cache" with the maximum value that can be found, starting from the end, to avoid a linear search below
	maxValueAt := make([]int, len(events))
	maxValueAt[len(events)-1] = events[len(events)-1][2]
	for i := len(events) - 2; i >= 0; i-- {
		maxValueAt[i] = max(maxValueAt[i+1], events[i][2])
	}

	maxValue := 0
	for i, a := range events {
		// a single event could have a greater value than any combination of 2 events
		maxValue = max(a[2], maxValue)

        // find the position for the first non-overlapping event after the current
		firstNonOverlapping := findFirstAfterTarget(events, events[i][1]+1, i+1, len(events) - 1)

		if firstNonOverlapping >= i+1 && firstNonOverlapping < len(events) {
            // because we "cached" the value for the maximum value up until this point, we don't need to iterate
			value := a[2] + maxValueAt[firstNonOverlapping]
			maxValue = max(value, maxValue)
		}
	}
	return maxValue
}

func findFirstAfterTarget(events [][]int, target, lo, hi int) int {
	for lo <= hi {
		mid := (lo + hi) / 2
		if events[mid][0] >= target {
			hi = mid - 1
		} else {
			lo = mid + 1
		}
	}
	return lo
}