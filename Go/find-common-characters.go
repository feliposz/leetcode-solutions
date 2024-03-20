func commonChars(words []string) []string {
    var freqMin, freqWord [26]int
    for i := range freqMin {
        freqMin[i] = 1000 // just need to be larger than 100
    }
    for i := range words {
        for _, c := range []byte(words[i]) {
            freqWord[c-'a']++
        }
        for c := range freqMin {
            freqMin[c] = min(freqMin[c], freqWord[c])
            freqWord[c] = 0
        }
    }
    result := make([]string, 0)
    for c := range freqMin {
        for i := 0; i < freqMin[c]; i++ {
            result = append(result, string(c + 'a'))
        }
    }
    return result
}