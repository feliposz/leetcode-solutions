func tictactoe(moves [][]int) string {
	ttt := [3][3]string{}
	player := "A"
	count := 0
	for _, m := range moves {
		ttt[m[0]][m[1]] = player
		if player == "A" {
			player = "B"
		} else {
			player = "A"
		}
		for i := 0; i < 3; i++ {
			if ttt[i][0] != "" && ttt[i][0] == ttt[i][1] && ttt[i][1] == ttt[i][2] {
				return ttt[i][0]
			} else if ttt[0][i] != "" && ttt[0][i] == ttt[1][i] && ttt[1][i] == ttt[2][i] {
				return ttt[0][i]
			}
		}
		if ttt[1][1] != "" {
			if ttt[0][0] == ttt[1][1] && ttt[1][1] == ttt[2][2] {
				return ttt[0][0]
			} else if ttt[0][2] == ttt[1][1] && ttt[1][1] == ttt[2][0] {
				return ttt[0][2]
			}
		}
		count++
	}
	if count == 9 {
		return "Draw"
	}
	return "Pending"
}