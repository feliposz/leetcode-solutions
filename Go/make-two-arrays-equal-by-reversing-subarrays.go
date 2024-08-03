func canBeEqual(target []int, arr []int) bool {
    a := [1001]int{}
    for _, x := range target {
        a[x]++
    }
    for _, x := range arr {
        if a[x] > 0 {
            a[x]--
        } else {
            return false
        }
    }
    return true
}