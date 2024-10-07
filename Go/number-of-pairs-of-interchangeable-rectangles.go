func interchangeableRectangles(rectangles [][]int) int64 {
	ratios := map[float64]int64{}
	for _, r := range rectangles {
		ratios[float64(r[0])/float64(r[1])]++
	}
	count := int64(0)
	for _, c := range ratios {
		count += c * (c - 1) / 2
	}
	return count
}