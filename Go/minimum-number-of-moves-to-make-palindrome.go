func minMovesToMakePalindrome(s string) int {
	return countMoves([]byte(s))
}

func countMoves(s []byte) int {
	// if leftmost and rightmost chars are equal, remove them and recurse
	// otherwise, check which side requires fewer moves, do the swaps and recurse
	size := len(s)
	//fmt.Println("before swaps = ", s)
	if size < 2 {
		return 0
	}
	if s[0] == s[size-1] {
		return countMoves(s[1 : size-1])
	}
	left, right := -1, -1
	for i := 0; i < size; i++ {
		if s[i] == s[size-1] {
			left = i
			break
		}
	}
	if left == -1 {
		//fmt.Println(s)
		panic("invalid input")
	}
	for i := 0; i < size; i++ {
		if s[size-i-1] == s[0] {
			right = i
			break
		}
	}
	if right == -1 {
		panic("invalid input")
	}
	swaps := 0
	if left < right {
		//fmt.Println("swapping from left: ", left)
		for i := left - 1; i >= 0; i-- {
			s[i], s[i+1] = s[i+1], s[i]
			swaps++
		}
	} else {
		//fmt.Println("swapping from right: ", right)
		for i := size - right; i < size; i++ {
			s[i], s[i-1] = s[i-1], s[i]
			swaps++
		}
	}
	//fmt.Println("after swaps = ", s)
	return swaps + countMoves(s[1:size-1])
}