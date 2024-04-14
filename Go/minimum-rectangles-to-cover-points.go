func minRectanglesToCoverPoints(points [][]int, w int) int {
    slices.SortFunc(points, func (a, b []int) int {
        return a[0] - b[0]
    })
    currMaxX := -1
    rectangles := 0
    for _, p := range points {
        if p[0] > currMaxX {
            currMaxX = p[0] + w
            rectangles++
        }
    }
    return rectangles
}