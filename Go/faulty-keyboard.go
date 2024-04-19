func finalString(s string) string {
    result := make([]rune, 0, len(s))
    for _, c := range s {
        if c == 'i' {
            slices.Reverse(result)
        } else {
            result = append(result, c)
        }
    }
    return string(result)
}