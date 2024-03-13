func solveSudoku(board [][]byte) {
	d := newDraft()
	d.MarkCandidates(board)
	d, _ = solveDraft(d)
	//d.Print("The end")
	d.WriteSolved(board)
}

type draft [9][9]uint16

func newDraft() (d draft) {
	for i := range d {
		for j := range d[i] {
			// this is a bitmap of candidates (bits 1-9) for each cell in the board
			d[i][j] = 0b0000000111111111
		}
	}
	return
}

func solveDraft(d draft) (draft, bool) {
	changed := true
	for changed {
		// possibilities := 1.0
		// for r := 0; r < 9; r++ {
		// 	for c := 0; c < 9; c++ {
		// 		possibilities *= float64(countCandidates(d[r][c]))
		// 	}
		// }
		// fmt.Printf("Bad luck. Possibilities remaining: %f\n", possibilities)
		d.ClearSingles()
		//d.Print("After clearing singles:")
		complete, solvable := d.Check()
		if !solvable {
			return d, false
		} else if complete {
			return d, true
		}
		changed = d.ClearNakedPairs()
		//d.Print("After clearing naked pairs:")
		if changed {
			continue
		}
		changed = d.ClearHiddenPairs()
		//d.Print("After clearing hidden pairs:")
		if changed {
			continue
		}
		changed = d.ClearNakedTriples()
		//d.Print("After clearing naked triples:")
		if changed {
			continue
		}
		changed = d.ClearHiddenTriples()
		//d.Print("After clearing hidden triples:")
		if changed {
			continue
		}
	}

	// for each candidate:
	// 1. make a copy of the current draft
	// 2. set the value for the cell
	// 3. try to solve the problem recursively
	// 4. if solution is found, return it
	// 5. else, try next candidate

	// find cell with the fewest possible candidates
	guess := struct{ r, c, candidates int }{-1, -1, 10}
	for r := 0; r < 9; r++ {
		for c := 0; c < 9; c++ {
			cell := d[r][c]
			// check if more than 1 bit is set
			if cell&(cell-1) != 0 {
				candidates := countCandidates(cell)
				if candidates < guess.candidates {
					guess.r = r
					guess.c = c
					guess.candidates = candidates
					if guess.candidates == 2 {
						break
					}
				}
			}
		}
		if guess.candidates == 2 {
			break
		}
	}

	if guess.r == -1 {
		return d, false
	}
	for i := 1; i <= 9; i++ {
		if d[guess.r][guess.c]&(1<<(i-1)) != 0 {
			d2 := d
			d2.Set(guess.r, guess.c, i)
			d2, completed := solveDraft(d2)
			if completed {
				return d2, true
			}
		}
	}
	return d, false
}

// mark initial candidates according to given sudoku board
func (d *draft) MarkCandidates(board [][]byte) {
	for r := 0; r < 9; r++ {
		for c := 0; c < 9; c++ {
			if board[r][c] >= '1' && board[r][c] <= '9' {
				d.Set(r, c, int(board[r][c]-'0'))
			}
		}
	}
}

// write solved cells to board (skip unsolved)
func (d *draft) WriteSolved(board [][]byte) {
	for r := 0; r < 9; r++ {
		for c := 0; c < 9; c++ {
			cell := d[r][c]
			// check if only 1 bit is set
			if cell&(cell-1) == 0 {
				for n := 1; n <= 9; n++ {
					if d[r][c] == (1 << (n - 1)) {
						board[r][c] = byte(n + '0')
						break
					}
				}
			}
		}
	}
}

// set a single cell value and clear the other candidates
func (d *draft) Set(row, col, num int) {
	setMask := uint16(1 << (num - 1))
	clearMask := ^setMask
	// clear bits in the same column
	for r := 0; r < 9; r++ {
		d[r][col] &= clearMask
	}
	// clear bits in the same row
	for c := 0; c < 9; c++ {
		d[row][c] &= clearMask
	}
	// clear bits in the same square
	for i := 0; i < 9; i++ {
		r := i%3 + (row/3)*3
		c := i/3 + (col/3)*3
		d[r][c] &= clearMask
	}
	// finally set the bit in the target cell
	d[row][col] = setMask
}

// look for remaining single candidates
func (d *draft) ClearSingles() {
	old := *d
	for {
		for r := 0; r < 9; r++ {
			for c := 0; c < 9; c++ {
				cell := d[r][c]
				// check if only 1 bit is set
				if cell&(cell-1) == 0 {
					for n := 1; n <= 9; n++ {
						if cell == (1 << (n - 1)) {
							// force clearing the other cells
							d.Set(r, c, n)
							break
						}
					}
				}
			}
		}
		// if nothing was cleared in this loop, there are no more single cells left to clear
		if old == *d {
			break
		}
		old = *d
	}
}

func countCandidates(n uint16) int {
	count := 0
	for n > 0 {
		count += int(n & 1)
		n >>= 1
	}
	return count
}

// look up for naked pairs
func (d *draft) ClearNakedPairs() bool {
	old := *d
	// same row
	for r := 0; r < 9; r++ {
		for c1 := 0; c1 < 9; c1++ {
			for c2 := c1 + 1; c2 < 9; c2++ {
				// check if its a naked pair
				if d[r][c1] == d[r][c2] && countCandidates(d[r][c1]) == 2 {
					// clear the other columns...
					clearMask := ^d[r][c1]
					for c3 := 0; c3 < 9; c3++ {
						if c3 != c1 && c3 != c2 {
							d[r][c3] &= clearMask
						}
					}
				}
			}
		}
	}
	// same col
	for c := 0; c < 9; c++ {
		for r1 := 0; r1 < 9; r1++ {
			for r2 := r1 + 1; r2 < 9; r2++ {
				// check if its a naked pair
				if d[r1][c] == d[r2][c] && countCandidates(d[r1][c]) == 2 {
					// clear the other rows...
					clearMask := ^d[r1][c]
					for r3 := 0; r3 < 9; r3++ {
						if r3 != r1 && r3 != r2 {
							d[r3][c] &= clearMask
						}
					}
				}
			}
		}
	}
	// same square
	for q := 0; q < 9; q++ {
		for i := 0; i < 9; i++ {
			r1 := i%3 + (q%3)*3
			c1 := i/3 + (q/3)*3
			for j := i + 1; j < 9; j++ {
				r2 := j%3 + (q%3)*3
				c2 := j/3 + (q/3)*3
				// check if its a naked pair
				if d[r1][c1] == d[r2][c2] && countCandidates(d[r1][c1]) == 2 {
					// clear the other cells..
					clearMask := ^d[r1][c1]
					for k := 0; k < 9; k++ {
						r3 := k%3 + (q%3)*3
						c3 := k/3 + (q/3)*3
						if !(r3 == r1 && c3 == c1) && !(r3 == r2 && c3 == c2) {
							d[r3][c3] &= clearMask
						}
					}
				}
			}
		}
	}
	return old != *d
}

// look up for naked pairs
func (d *draft) ClearNakedTriples() bool {
	old := *d
	// same row
	for r := 0; r < 9; r++ {
		for c1 := 0; c1 < 9; c1++ {
			for c2 := c1 + 1; c2 < 9; c2++ {
				// check the first 2 of the naked triple, before looping the 3rd
				if d[r][c1] == d[r][c2] && countCandidates(d[r][c1]) == 3 {
					for c3 := c2 + 1; c3 < 9; c3++ {
						if d[r][c1] == d[r][c3] {
							// clear the other columns...
							clearMask := ^d[r][c1]
							for c4 := 0; c4 < 9; c4++ {
								if c4 != c1 && c4 != c2 && c4 != c3 {
									d[r][c4] &= clearMask
								}
							}
						}
					}
				}
			}
		}
	}
	// same col
	for c := 0; c < 9; c++ {
		for r1 := 0; r1 < 9; r1++ {
			for r2 := r1 + 1; r2 < 9; r2++ {
				// check the first 2 of the naked triple, before looping the 3rd
				if d[r1][c] == d[r2][c] && countCandidates(d[r1][c]) == 3 {
					for r3 := r2 + 1; r3 < 9; r3++ {
						if d[r1][c] == d[r3][c] {
							// clear the other rows...
							clearMask := ^d[r1][c]
							for r4 := 0; r4 < 9; r4++ {
								if r4 != r1 && r4 != r2 && r4 != r3 {
									d[r4][c] &= clearMask
								}
							}
						}
					}
				}
			}
		}
	}
	// same square
	for q := 0; q < 9; q++ {
		for i := 0; i < 9; i++ {
			r1 := i%3 + (q%3)*3
			c1 := i/3 + (q/3)*3
			for j := i + 1; j < 9; j++ {
				r2 := j%3 + (q%3)*3
				c2 := j/3 + (q/3)*3
				// check the first 2 of the naked triple, before looping the 3rd
				if d[r1][c1] == d[r2][c2] && countCandidates(d[r1][c1]) == 3 {
					for k := j + 1; k < 9; k++ {
						r3 := k%3 + (q%3)*3
						c3 := k/3 + (q/3)*3
						if d[r1][c1] == d[r3][c3] {
							// clear the other cells..
							clearMask := ^d[r1][c1]
							for l := 0; l < 9; l++ {
								r4 := l%3 + (q%3)*3
								c4 := l/3 + (q/3)*3
								if !(r4 == r1 && c4 == c1) && !(r4 == r2 && c4 == c2) && !(r4 == r3 && c4 == c3) {
									d[r4][c4] &= clearMask
								}
							}
						}
					}
				}
			}
		}
	}
	return old != *d
}

// look up for hidden pairs
func (d *draft) ClearHiddenPairs() bool {
	old := *d
	// same row
	for r := 0; r < 9; r++ {
		for c1 := 0; c1 < 9; c1++ {
			for c2 := c1 + 1; c2 < 9; c2++ {
				candidatePair := d[r][c1] & d[r][c2]
				// check if its a hidden pair
				if candidatePair != 0 && countCandidates(candidatePair) == 2 {
					isHiddenPair := true
					// check if other cells contain the pair
					for c3 := 0; c3 < 9; c3++ {
						if c3 != c1 && c3 != c2 && d[r][c3]&candidatePair != 0 {
							isHiddenPair = false
							break
						}
					}
					if isHiddenPair {
						// clear the other candidates
						d[r][c1] = candidatePair
						d[r][c2] = candidatePair
					}
				}
			}
		}
	}
	// same col
	for c := 0; c < 9; c++ {
		for r1 := 0; r1 < 9; r1++ {
			for r2 := r1 + 1; r2 < 9; r2++ {
				candidatePair := d[r1][c] & d[r2][c]
				// check if its a hidden pair
				if candidatePair != 0 && countCandidates(candidatePair) == 2 {
					isHiddenPair := true
					// check if other cells contain the pair
					for r3 := 0; r3 < 9; r3++ {
						if r3 != r1 && r3 != r2 && d[r3][c]&candidatePair != 0 {
							isHiddenPair = false
							break
						}
					}
					if isHiddenPair {
						// clear the other candidates
						d[r1][c] = candidatePair
						d[r2][c] = candidatePair
					}
				}
			}
		}
	}
	// same square
	for q := 0; q < 9; q++ {
		for i := 0; i < 9; i++ {
			r1 := i%3 + (q%3)*3
			c1 := i/3 + (q/3)*3
			for j := i + 1; j < 9; j++ {
				r2 := j%3 + (q%3)*3
				c2 := j/3 + (q/3)*3
				candidatePair := d[r1][c1] & d[r2][c2]
				// check if its a hidden pair
				if candidatePair != 0 && countCandidates(candidatePair) == 2 {
					isHiddenPair := true
					// check if other cells contain the pair
					for k := 0; k < 9; k++ {
						r3 := k%3 + (q%3)*3
						c3 := k/3 + (q/3)*3
						if !(r3 == r1 && c3 == c1) && !(r3 == r2 && c3 == c2) && d[r3][c3]&candidatePair != 0 {
							isHiddenPair = false
							break
						}
					}
					if isHiddenPair {
						// clear the other candidates
						d[r1][c1] = candidatePair
						d[r2][c2] = candidatePair
					}
				}
			}
		}
	}
	return old != *d
}

// look up for hidden pairs
func (d *draft) ClearHiddenTriples() bool {
	old := *d
	// same row
	for r := 0; r < 9; r++ {
		for c1 := 0; c1 < 9; c1++ {
			for c2 := c1 + 1; c2 < 9; c2++ {
				candidateTriple := d[r][c1] & d[r][c2]
				// check the first 2 of the naked triple, before looping the 3rd
				if candidateTriple != 0 && countCandidates(candidateTriple) == 3 {
					for c3 := c2 + 1; c3 < 9; c3++ {
						if d[r][c3]&candidateTriple == candidateTriple {
							// check if other cells contain the triple
							isHiddenTriple := true
							for c4 := 0; c4 < 9; c4++ {
								if c4 != c1 && c4 != c2 && c4 != c3 && candidateTriple&d[r][c4] != 0 {
									isHiddenTriple = false
									break
								}
							}
							if isHiddenTriple {
								// clear the other candidates
								d[r][c1] = candidateTriple
								d[r][c2] = candidateTriple
								d[r][c3] = candidateTriple
							}
						}
					}
				}
			}
		}
	}
	// same col
	for c := 0; c < 9; c++ {
		for r1 := 0; r1 < 9; r1++ {
			for r2 := r1 + 1; r2 < 9; r2++ {
				candidateTriple := d[r1][c] & d[r2][c]
				// check the first 2 of the naked triple, before looping the 3rd
				if candidateTriple != 0 && countCandidates(candidateTriple) == 3 {
					for r3 := r2 + 1; r3 < 9; r3++ {
						if d[r3][c]&candidateTriple == candidateTriple {
							// check if other cells contain the triple
							isHiddenTriple := true
							for r4 := 0; r4 < 9; r4++ {
								if r4 != r1 && r4 != r2 && r4 != r3 && candidateTriple&d[r4][c] != 0 {
									isHiddenTriple = false
									break
								}
							}
							if isHiddenTriple {
								// clear the other candidates
								d[r1][c] = candidateTriple
								d[r2][c] = candidateTriple
								d[r3][c] = candidateTriple
							}
						}
					}
				}
			}
		}
	}
	// same square
	for q := 0; q < 9; q++ {
		for i := 0; i < 9; i++ {
			r1 := i%3 + (q%3)*3
			c1 := i/3 + (q/3)*3
			for j := i + 1; j < 9; j++ {
				r2 := j%3 + (q%3)*3
				c2 := j/3 + (q/3)*3
				candidateTriple := d[r1][c1] & d[r2][c2]
				// check the first 2 of the naked triple, before looping the 3rd
				if candidateTriple != 0 && countCandidates(candidateTriple) == 3 {
					for k := j + 1; k < 9; k++ {
						r3 := k%3 + (q%3)*3
						c3 := k/3 + (q/3)*3
						if d[r3][c3]&candidateTriple == candidateTriple {
							// clear the other cells..
							// check if other cells contain the triple
							isHiddenTriple := true
							for l := 0; l < 9; l++ {
								r4 := l%3 + (q%3)*3
								c4 := l/3 + (q/3)*3
								if !(r4 == r1 && c4 == c1) && !(r4 == r2 && c4 == c2) && !(r4 == r3 && c4 == c3) && candidateTriple&d[r4][c4] != 0 {
									isHiddenTriple = false
									break
								}
							}
							if isHiddenTriple {
								// clear the other candidates
								d[r1][c1] = candidateTriple
								d[r2][c2] = candidateTriple
								d[r3][c3] = candidateTriple
							}
						}
					}
				}
			}
		}
	}
	return old != *d
}

// check if there are only single candidates left
func (d *draft) Check() (complete, solvable bool) {
	for r := 0; r < 9; r++ {
		for c := 0; c < 9; c++ {
			cell := d[r][c]
			if cell == 0 {
				return false, false
			} else if cell&(cell-1) != 0 { // check if more than 1 bit is set
				return false, true
			}
		}
	}
	return true, true
}

func (d *draft) Print(message string) {
	fmt.Println(message)
	for r := 0; r < 9; r++ {
		for c := 0; c < 9; c++ {
			for n := 1; n <= 9; n++ {
				if d[r][c]&(1<<(n-1)) != 0 {
					fmt.Printf("%d", n)
				} else {
					fmt.Print(".")
				}
			}
			if c == 2 || c == 5 {
				fmt.Print(" | ")
			} else {
				fmt.Print(" ")
			}
		}
		fmt.Println()
		if r == 2 || r == 5 {
			fmt.Println("------------------------------+-------------------------------+------------------------------")
		}
	}
}

func boardsAreEqual(left, right [][]byte) bool {
	for i := range left {
		if slices.Compare(left[i], right[i]) != 0 {
			return false
		}
	}
	return true
}

func convertRawStringToSudokuBoard(raw string) (board [][]byte) {
	data := [][]string{}
	json.Unmarshal([]byte(raw), &data)
	if len(data) != 9 {
		panic("expected 9 rows")
	}
	for _, row := range data {
		if len(row) != 9 {
			panic("expected 9 cols")
		}
	}
	board = convert2DStringToByte(data)
	return
}

func convert2DStringToByte(input [][]string) (output [][]byte) {
	output = make([][]byte, len(input))
	for i := range input {
		output[i] = make([]byte, len(input[i]))
		for j := range input[i] {
			output[i][j] = input[i][j][0]
		}
	}
	return
}
