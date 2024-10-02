func hasAllCodes(s string, k int) bool {
    size := 1 << k
    mask := size - 1
    // fmt.Printf("size: %d\n", size)
    // fmt.Printf("mask: %b\n", mask)
    codes := make([]bool, size)
    curr := 0
    acc := 0
    for _, x := range s {
        curr = ((curr << 1) | int(x-'0')) & mask
        acc++
        if acc >= k {
            // fmt.Printf("curr: %b\n", curr)
            codes[curr] = true
        }
    }
    for _, present := range codes {
        // fmt.Printf("code: %b %v\n", code, present)
        if !present {
            return false
        }
    }
    return true
}