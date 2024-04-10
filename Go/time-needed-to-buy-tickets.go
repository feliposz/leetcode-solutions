func timeRequiredToBuy(tickets []int, k int) int {
	time := 0
	tk := tickets[k]
	for i, t := range tickets {
		if i <= k {
			time += min(t, tk)
		} else {
			time += min(t, tk-1)
		}
	}
	return time
}

func SIMULATION_timeRequiredToBuy(tickets []int, k int) int {
	next, time := 0, 0
	for {
		if tickets[next] > 0 {
			tickets[next]--
			time++
			if k == next && tickets[next] == 0 {
				return time
			}
		}
		next++
		if next == len(tickets) {
			next = 0
		}
	}
}