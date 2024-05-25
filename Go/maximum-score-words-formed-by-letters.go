func maxScoreWords(words []string, letters []byte, score []int) int {
    available := [26]int{}
    for _, letter := range letters {
        available[letter-'a']++
    }
    return calcMaxScore(words, available, score)
}

func calcWordScore(word string, available [26]int, score []int) (int, [26]int) {
    updated := available
    total := 0
    for _, letter := range []byte(word) {
        idx := letter-'a'
        if updated[idx] > 0 {
            updated[idx]--
            total += score[idx]
        } else {
            return 0, available
        }
    }
    return total, updated
}

func calcMaxScore(words []string, available [26]int, score []int) int {
    if len(words) == 0 {
        return 0
    }
    wordScore, updated := calcWordScore(words[0], available, score)
    withWord := 0
    if wordScore > 0 {
        withWord = wordScore + calcMaxScore(words[1:], updated, score)
    }
    withoutWord := calcMaxScore(words[1:], available, score)
    return max(withWord, withoutWord)
}