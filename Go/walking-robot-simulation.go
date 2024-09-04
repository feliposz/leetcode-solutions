func robotSim(commands []int, obstacles [][]int) int {
	x, y := 0, 0
	dir := 0
	obs := map[string]bool{}
	for _, ob := range obstacles {
		obs[fmt.Sprintf("%d,%d", ob[0], ob[1])] = true
	}
	dist := 0
	for _, cmd := range commands {
		switch cmd {
		case -2:
			dir = (dir - 1 + 4) % 4
		case -1:
			dir = (dir + 1 + 4) % 4
		default:
			dx, dy := 0, 0
			switch dir {
			case 0:
				dy = 1
			case 1:
				dx = 1
			case 2:
				dy = -1
			case 3:
				dx = -1
			}
			for i := 0; i < cmd; i++ {
				pos := fmt.Sprintf("%d,%d", x+dx, y+dy)
				// fmt.Println("check", pos)
				if obs[pos] {
					// fmt.Println("blocked at ", pos)
					break
				}
				x += dx
				y += dy
			}
			dist = max(dist, x*x+y*y)
		}
	}
	return dist
}