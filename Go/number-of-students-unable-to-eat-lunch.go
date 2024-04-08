func countStudents(students []int, sandwiches []int) int {
	studentSquares, studentCirculars := 0, 0
	for _, s := range students {
		if s == 0 {
			studentSquares++
		} else {
			studentCirculars++
		}
	}
	for _, s := range sandwiches {
		if s == 0 {
			studentSquares--
            if studentSquares < 0 {
                return studentCirculars
            }
		} else {
			studentCirculars--
            if studentCirculars < 0 {
                return studentSquares
            }
		}
	}
	return 0
}