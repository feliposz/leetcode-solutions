func countTriplets(arr []int) int {
    count := 0
    for i := 0; i < len(arr); i++ {
        a := arr[i]
        for j := i + 1; j < len(arr); j++ {
            b := 0
            for k := j; k < len(arr); k++ {
                b ^= arr[k]
                if a == b {
                    count++
                }
            }
            a ^= arr[j]
        }
    }
    return count
}