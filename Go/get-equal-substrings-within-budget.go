func equalSubstring(s string, t string, maxCost int) int {
    left := 0
    cost := 0
    maxLength := 0
    for right := range s {
        cost += abs(int(s[right]) - int(t[right]))
        //fmt.Println(left, right, cost)
        for cost > maxCost && left <= right {
            cost -= abs(int(s[left]) - int(t[left]))
            left++
        }
        maxLength = max(maxLength, right - left +1)
    }
    return maxLength
}

func abs(x int) int {
    if x < 0 {
        return -x
    }
    return x
}