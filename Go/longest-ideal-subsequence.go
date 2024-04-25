func longestIdealString(s string, k int) int {
    // keep track of the length of the longest sequence ending in letter 0-25 => a-z
    sequenceEndingInLetter := [26]int{}
    result := 0

    for _, letter := range s {
        maxLen := 0
        // check length of possible predecessors/successors within k range
        for d := -k; d <= k; d++ {
            otherLetter := int(letter-'a') + d
			if otherLetter >= 0 && otherLetter < 26 {
                maxLen = max(maxLen, sequenceEndingInLetter[otherLetter])
            }
        }
        // update length of the current letter subsequence
        sequenceEndingInLetter[letter-'a'] = maxLen + 1
        result = max(result, sequenceEndingInLetter[letter-'a'])
    }

    return result
}
