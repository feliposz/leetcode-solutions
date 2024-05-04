func numRescueBoats(people []int, limit int) int {
    slices.Sort(people)
    left, right := 0, len(people)-1
    boats := 0
    curr := 0
    count := 0
    for left <= right {
        for count < 2 && left <= right && curr + people[right] <= limit {
            curr += people[right]
            count++
            right--
        }
        for count < 2 && left <= right && curr + people[left] <= limit {
            curr += people[left]
            count++
            left++
        }
        curr = 0
        count = 0
        boats++
    }
    return boats
}