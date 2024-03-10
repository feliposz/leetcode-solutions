func minimumBoxes(apple []int, capacity []int) int {
    m := len(capacity)
    total := 0
    for _, a := range apple {
        total += a
    }
    if total == 0 {
        return 0
    }
    slices.Sort(capacity)
    for i := m-1; i >= 0; i-- {
        total -= capacity[i]
        if total <= 0 {
            return m-i
        }
    }
    return m
}