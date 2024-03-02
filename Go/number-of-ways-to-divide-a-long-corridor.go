func numberOfWays(corridor string) int {
    // divide corridor into segments that start and end with a seat
    starts := make([]int, 0, len(corridor)/2)
    ends := make([]int, 0, len(corridor)/2)
    inside := false
    start := 0
    for i, object := range corridor {
        if object == 'S' {
            if inside {
                starts = append(starts, start)
                ends = append(ends, i)
                inside = false
            } else {
                start = i
                inside = true
            }
        }
    }
    // ended inside a segment or there where no seats present
    if inside || len(starts) == 0 {
        return 0
    }
    //fmt.Println("Segments:")
    //for i := range starts {
    //    fmt.Println(starts[i], ends[i])
    //}
    ways := 1
    // the intervals between each segment indicate in how many positions a divider can be placed
    //fmt.Println("Intervals:")
    for i := 0; i < len(starts) - 1; i++ {
        space := starts[i+1] - ends[i]
        ways = (ways * space) % 1000000007
        //fmt.Println(space, ways)
    }
    return int(ways % 1000000007)
}