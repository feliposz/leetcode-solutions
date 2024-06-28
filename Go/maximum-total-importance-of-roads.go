func maximumImportance(n int, roads [][]int) int64 {
    conn := make([]int, n)
    for _, r := range roads {
        conn[r[0]]++
        conn[r[1]]++
    }
    // fmt.Println("conn => ", conn)
    cities := make([]city, 0, n)
    for i, c := range conn {
        cities = append(cities, city{i, c, 0})
    }
    slices.SortFunc(cities, func (a, b city) int {
        return a.connections - b.connections
    })
    for i := range cities {
        cities[i].importance = i + 1
    }
    // fmt.Println("cities => ", cities)    
    imp := make([]int, n)
    for _, c := range cities {
        imp[c.id] = c.importance
    }
    // fmt.Println("imp => ", imp)
    total := int64(0)
    for _, r := range roads {
        total += int64(imp[r[0]] + imp[r[1]])
    }
    return total
}

type city struct {
    id, connections, importance int
}