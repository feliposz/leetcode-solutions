func specialArray(nums []int) int {
    for x := 0; x <= len(nums); x++ {
        count := 0
        for _, n := range nums {
            if n >= x {
                count++
            }
        }
        if count == x {
            return x
        }
    }
    return -1
}