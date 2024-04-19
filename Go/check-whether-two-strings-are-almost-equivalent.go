func checkAlmostEquivalent(word1 string, word2 string) bool {
    freq1 := [26]int{}
    freq2 := [26]int{}
    for _, c := range word1 {
        freq1[c-'a']++
    }
    for _, c := range word2 {
        freq2[c-'a']++
    }
    for i := range freq1 {
        if abs(freq1[i] - freq2[i]) > 3 {
            return false
        }
    }
    return true
}

func abs(x int) int {
    if x < 0 {
        return -x
    }
    return x
}