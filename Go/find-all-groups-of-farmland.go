func findFarmland(land [][]int) [][]int {
    m, n := len(land), len(land[0])
    farmlands := [][]int{}
    for i := 0; i < m; i++ {
        for j := 0; j < n; j++ {
            if land[i][j] == 1 {
                k, l := checkFarmland(land, i, j)
                farmlands = append(farmlands, []int{i, j, k, l})
                for y := i; y <= k; y++ {
                    for x := j; x <= l; x++ {
                        land[y][x] = 0
                    }
                }
            }
        }
    }
    return farmlands
}

func checkFarmland(land [][]int, i, j int) (k, l int) {
    for i < len(land) && land[i][j] == 1 {
        k = i
        i++
    }
    for j < len(land[0]) && land[k][j] == 1 {
        l = j
        j++
    }
    return
}