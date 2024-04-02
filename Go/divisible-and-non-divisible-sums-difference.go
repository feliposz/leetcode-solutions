func differenceOfSums(n int, m int) int {
    var num1, num2 int
    for i := 1; i <= n; i++ {
        if i % m != 0 {
            num1 += i
        } else {
            num2 += i
        }
    }
    return num1 - num2
}