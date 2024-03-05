func minimumLength(s string) int {
    if len(s) == 1 {
        return 1
    }
    left, right := 0, len(s) - 1
    for left < right && s[left] == s[right]{
        base := s[left]
        for left <= right && base == s[left] {
            left++
        }
        for right > left && base == s[right] {
            right--
        }
    }
    return right - left + 1
}