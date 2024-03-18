func findMinArrowShots(points [][]int) int {
    // sort the balloons based on coordinate
    slices.SortFunc(points, func (a, b []int) int {
        return a[0] - b[0]
    })
    // keep track of arrows shot so far
    arrows := 1 // assume first arrow was already shot before we check other balloons
    prevArrowPosition := points[0][1]
    for _, p := range points {
        if p[0] > prevArrowPosition {
            // the previous arrow missed this balloon, because its starting coordinate is to the right of the arrow
            // so we need to add another arrow and update the new coordinate for it
            arrows++
            prevArrowPosition = p[1]
        } else {
            // if this ballon could be shot, adjust the position of the arrow slightly
            // so that more balloons can possibly be hit later
            prevArrowPosition = min(prevArrowPosition, p[1])
        }
    }
    return arrows
}