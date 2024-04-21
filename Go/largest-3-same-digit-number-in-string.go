func largestGoodInteger(num string) string {
    var prev, largest rune
    count := 0
    for _, curr := range num {
        if curr == prev {
            count++
            if count == 3 {
                if curr > largest {
                    largest = curr
                }
            }
        } else {
            prev = curr
            count = 1
        }
    }
    if largest > 0 {
        return fmt.Sprintf("%c%c%c", largest, largest, largest)
    }
    return ""
}