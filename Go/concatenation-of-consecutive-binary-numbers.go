func concatenatedBinary(n int) int {
    result := 0
    limit := 1
    mod := 1000000007
    shift := 0
    for i := 1; i <= n; i++ {
        if i >= limit {
            limit *= 2
            shift++
        }
        result = (result << shift + i) % mod
        //fmt.Printf("%b\n", result)
    }
    return result
}