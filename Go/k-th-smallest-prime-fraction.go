func kthSmallestPrimeFraction(arr []int, k int) []int {
    fractions := []fraction{}
    for i := 0; i < len(arr); i++ {
        for j := i + 1; j < len(arr); j++ {
            value := float64(arr[i]) / float64(arr[j])
            fractions = append(fractions, fraction{value, arr[i], arr[j]})
        }
    }
    slices.SortFunc(fractions, func (a, b fraction) int {
        return cmp.Compare(a.value, b.value)
    })
    // fmt.Println(fractions)
    return []int{fractions[k-1].num, fractions[k-1].den}
}

type fraction struct {
    value float64
    num int
    den int
}