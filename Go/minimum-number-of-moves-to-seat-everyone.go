func minMovesToSeat(seats []int, students []int) int {
	slices.Sort(seats)
	slices.Sort(students)
	moves := 0
	for i := range seats {
		moves += abs(seats[i] - students[i])
	}
	return moves
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}