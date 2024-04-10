func maxSatisfaction(satisfaction []int) int {
    slices.Sort(satisfaction)
    acc, curr := 0, 0
    for i := len(satisfaction) - 1; i >= 0; i-- {
        acc += satisfaction[i]
        if acc < 0 {
            break
        }
        curr += acc
    }
    return curr
}