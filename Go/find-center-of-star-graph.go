func findCenter(edges [][]int) int {
    degree := map[int]int{}
    for _, e := range edges {
        a, b := e[0], e[1]
        degree[a]++
        if degree[a] > 1 {
            return a
        }
        degree[b]++
        if degree[b] > 1 {
            return b
        }        
    }
    return -1
}