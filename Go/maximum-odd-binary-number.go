func maximumOddBinaryNumber(s string) string {
    zeros := 0
    ones := 0
    for _, c := range s {
        if c == '0' {
            zeros++
        } else {
            ones++
        }
    }
    ones--
    result := make([]byte, 0, len(s))
    for ones > 0 {
        result = append(result, '1')
        ones--
    }
    for zeros > 0 {
        result = append(result, '0')
        zeros--
    }
    result = append(result, '1')
    return string(result)
}