func trap(height []int) int {
	totalTrapped := 0
	trapped := 0
	top := 0
	left := 0
	segment := map[int]bool{}
	for i, h := range height {
		if h >= top {
    		totalTrapped += trapped
			if left != i {
				segment[left] = true
			}
			trapped = 0
			top = h
			left = i
		} else {
			trapped += top - h
		}
	}
	trapped = 0
	top = 0
	for i := len(height) - 1; i >= 0; i-- {
		h := height[i]
		if h >= top && !segment[i] {
			totalTrapped += trapped
			trapped = 0
			top = h
		} else {
			trapped += top - h
		}
	}
	return totalTrapped
}