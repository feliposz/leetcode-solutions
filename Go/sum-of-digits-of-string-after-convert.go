func getLucky(s string, k int) int {
    sum := 0
    for _, s := range s {
        value := int(s - 'a' + 1)
        sum += value % 10 + value / 10
    }
    for k > 1 {
        newSum := 0
        for sum > 0 {
            newSum += sum % 10
            sum /= 10
        }
        sum = newSum
        k--
    }
    return sum
}