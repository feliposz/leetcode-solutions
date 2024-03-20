func distanceBetweenBusStops(distance []int, start int, destination int) int {
    n := len(distance)
    travelA, travelB := 0, 0
    for i := start; i != destination; i = (i + 1) % n {
        travelA += distance[i]
    }
    for i := destination; i != start; i = (i + 1) % n {
        travelB += distance[i]
    }
    return min(travelA, travelB)
}