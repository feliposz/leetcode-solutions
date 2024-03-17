func countSubstrings(s string, c byte) int64 {
    count := int64(0)
    for _, b := range []byte(s) {
        if b == c {
            count++
        }
    }
    return (1 + count) * count / 2
}