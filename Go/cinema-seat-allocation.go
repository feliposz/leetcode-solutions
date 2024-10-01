func maxNumberOfFamilies(n int, reservedSeats [][]int) int {
	seats := map[int]int{}
	for _, reserved := range reservedSeats {
		row, col := reserved[0]-1, 10-reserved[1]
		seats[row] |= 1 << col
	}
	const left = 0b0111100000
	const right = 0b0000011110
	const center = 0b0001111000
	families := n * 2
	for _, row := range seats {
		// fmt.Printf("%010b\n", row)
		if row&left == 0 && row&right == 0 {
			// ok
		} else if row&left == 0 || row&right == 0 {
			families--
		} else if row&center == 0 {
			families--
		} else {
			families -= 2
		}
	}
	return families
}