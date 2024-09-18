func largestNumber(nums []int) string {
	parts := make([]string, len(nums))
    allZeroes := true
	for i, n := range nums {
        if n != 0 {
            allZeroes = false
        }
		parts[i] = strconv.Itoa(n)
	}
    if allZeroes {
        return "0"
    }
	slices.SortFunc(parts, func(a, b string) int {
		return cmp.Compare(b+a, a+b)
	})
	var b strings.Builder
	for _, s := range parts {
		b.WriteString(s)
	}
	return b.String()
}