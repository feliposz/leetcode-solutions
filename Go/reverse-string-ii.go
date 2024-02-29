func reverseStr(s string, k int) string {
    result := []byte(s)
    for i := 0; i < len(result); i += 2 * k {
        slices.Reverse(result[i:min(i+k, len(s))])
    }
    return string(result)
}