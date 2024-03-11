func customSortString(order string, s string) string {
    var charOrder [26]int
    next := 1
    for _, char := range order {
        if charOrder[char-'a'] == 0 {
            charOrder[char-'a'] = next
            next++            
        }
    }
    for i := range charOrder {
        if charOrder[i] == 0 {
            charOrder[i] = next
            next++
        }
    }
    tmp := []byte(s)
    slices.SortFunc(tmp, func(a, b byte) int {
        return charOrder[a - 'a'] - charOrder[b - 'a']
    })    
    return string(tmp)
}