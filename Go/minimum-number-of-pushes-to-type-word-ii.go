func minimumPushes(word string) int {
	letters := [26]int{}
	for _, c := range word {
		letters[c-'a']++
	}
	slices.SortFunc(letters[:], func(a, b int) int {
		return a - b
	})
	pushes := 0
	keysLeft := 8
	pushMult := 1
	for i := len(letters) - 1; i >= 0; i-- {
		if letters[i] > 0 {
			pushes += letters[i] * pushMult
			keysLeft--
			if keysLeft == 0 {
				keysLeft = 8
				pushMult++
			}
		} else {
			break
		}
	}
	return pushes
}