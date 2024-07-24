func sortJumbled(mapping []int, nums []int) []int {
    mappedValues := make([]entry, len(nums))
    for i, n := range nums {
        mappedValues[i] = entry{n, i, mapValue(mapping, n)}
    }
    slices.SortFunc(mappedValues, func (a, b entry) int {
        if a.mapped == b.mapped {
            return a.pos - b.pos
        }
        return a.mapped - b.mapped
    })
    for i := range mappedValues {
        nums[i] = mappedValues[i].val
    }
    return nums
}

type entry struct {
    val int
    pos int
    mapped int
}

func mapValue(mapping []int, x int) int {
    digits := []byte(strconv.Itoa(x))
    for i, d := range digits {
        digits[i] = byte(mapping[d - '0'] + '0')
    }
    res, _ := strconv.Atoi(string(digits))
    return res
}