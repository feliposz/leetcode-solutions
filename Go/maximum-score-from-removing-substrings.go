func maximumGain(s string, x int, y int) int {
    points, count := 0, 0
    if x >= y {
        s, count = removeAndCount(s, "ab")
        points += x * count
        _, count = removeAndCount(s, "ba")
        points += y * count
    } else {
        s, count = removeAndCount(s, "ba")
        points += y * count
        _, count = removeAndCount(s, "ab")
        points += x * count
    }
    return points
}

func removeAndCount(s string, sub string) (string, int) {
    count := 0
    stack := make([]byte, len(s))
    top := -1
    for _, c := range s {
        if top >= 0 && byte(c) == sub[1] && stack[top] == sub[0] {
            count++
            top--
        } else {
            top++
            stack[top] = byte(c)
        }
    }    
    return string(stack[:top+1]), count
}
