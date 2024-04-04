func maxDepth(s string) int {
    result := 0
    depth := 0
    for _, c := range s {
        if c == '(' {
            depth++
        } else if c == ')' && depth > 0 {
            depth--
        }
        if depth > result {
            result = depth
        }
    }
    return result
}