func isNStraightHand(hand []int, groupSize int) bool {
    if len(hand) % groupSize != 0 {
        return false
    }
    slices.Sort(hand)
    cardCount := map[int]int{}
    for _, card := range hand {
        cardCount[card]++
    }
    for _, card := range hand[:len(hand)-groupSize+1] {
        if cardCount[card] == 0 {
            continue
        }
        for i := 1; i < groupSize; i++ {
            if cardCount[card+i] == 0 {
                return false
            }
        }
        for i := 0; i < groupSize; i++ {
            cardCount[card+i]--
        }
    }
    return true
}

func SLOW2_isNStraightHand(hand []int, groupSize int) bool {
    slices.Sort(hand)
    if len(hand) % groupSize != 0 {
        return false
    }
    groupCount := len(hand) / groupSize
    groups := make([]struct{last, size int}, groupCount)
    for _, card := range hand {
        for i := range groups {
            if groups[i].size < groupSize {
                if groups[i].size == 0 || card == groups[i].last + 1 {
                    groups[i].last = card
                    groups[i].size++
                    break
                }
            }
        }
    }
    for i := range groups {
        if groups[i].size != groupSize {
            return false
        }
    }
    return true
}

func SLOW_isNStraightHand(hand []int, groupSize int) bool {
    slices.Sort(hand)
    if len(hand) % groupSize != 0 {
        return false
    }
    groupCount := len(hand) / groupSize
    groups := make([][]int, groupCount)
    for _, card := range hand {
        for i := range groups {
            if len(groups[i]) < groupSize {
                if len(groups[i]) == 0 || card == groups[i][len(groups[i])-1] + 1 {
                    groups[i] = append(groups[i], card)
                    break
                }
            }
        }
    }
    for i := range groups {
        if len(groups[i]) != groupSize {
            return false
        }
    }
    return true
}