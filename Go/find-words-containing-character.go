func findWordsContaining(words []string, x byte) []int {
    res := []int{}
    for i, w := range words {
        for _, c := range []byte(w) {
            if c == x {
                res = append(res, i)
                break
            }
        }
    }
    return res
}