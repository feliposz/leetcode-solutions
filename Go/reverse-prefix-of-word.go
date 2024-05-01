func reversePrefix(word string, ch byte) string {
    b := []byte(word)
    pos := slices.Index(b, ch)
    if pos >= 0 {
        slices.Reverse(b[:pos+1])
    }
    return string(b)
}