func averageWaitingTime(customers [][]int) float64 {
    curr := 0
    totalWait := 0
    for _, c := range customers {
        arrival, prepare := c[0], c[1]
        if curr < arrival {
            curr = arrival
        }
        curr += prepare
        wait := curr - arrival
        totalWait += wait
    }
    return float64(totalWait) / float64(len(customers))
}