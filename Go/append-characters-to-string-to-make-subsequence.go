func appendCharacters(s string, t string) int {
    j := 0
    for _, c := range []byte(s) {
        if c == t[j] {
            j++
            if j >= len(t) {
                break
            }
        }
    }
    return len(t) - j
}