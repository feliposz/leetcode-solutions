func kthDistinct(arr []string, k int) string {
    count := map[string]int{}
    for _, s := range arr {
        count[s]++
    }
    i := 0
    for _, s := range arr {
        if count[s] == 1 {
           i++
           if i == k {
                return s 
           }           
        }
    }
    return ""
}