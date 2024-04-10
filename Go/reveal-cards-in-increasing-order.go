func deckRevealedIncreasing(deck []int) []int {
    // sort cards in desired order
    slices.Sort(deck)

    // make a queue of indices to simulate drawing
    queue := make([]int, len(deck))
    for i := range queue {
        queue[i] = i
    }

    // cards will be placed on their desired position
    result := make([]int, len(deck))

    for _, card := range deck {
        // simulate drawing the "show" card
        result[queue[0]] = card
        queue = queue[1:]
        if len(queue) > 0 {
            // simulate drawing the "skip" card and placing it on the back of the queue/deck
            queue = append(queue[1:], queue[0])
        }
    }

    return result
}