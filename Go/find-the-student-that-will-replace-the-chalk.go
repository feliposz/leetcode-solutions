func chalkReplacer(chalk []int, k int) int {
    i := 0
    sum := 0
    for _, c := range chalk {
        sum += c
    }
    k = k % sum
    for {
        if chalk[i] > k {
            return i
        }
        k -= chalk[i]
        i = (i + 1) % len(chalk)
    }
    return -1
}