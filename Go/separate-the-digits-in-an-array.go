func separateDigits(nums []int) []int {
	size := 0
	for _, num := range nums {
		if num >= 100000 {
			size += 6
		} else if num >= 10000 {
			size += 5
		} else if num >= 1000 {
			size += 4
		} else if num >= 100 {
			size += 3
		} else if num >= 10 {
			size += 2
		} else {
			size += 1
		}
	}
	result := make([]int, size)
	i := 0
	for _, num := range nums {
		if num >= 100000 {
			result[i] = num / 100000 % 10
			i++
		}
		if num >= 10000 {
			result[i] = num / 10000 % 10
			i++
		}
		if num >= 1000 {
			result[i] = num / 1000 % 10
			i++
		}
		if num >= 100 {
			result[i] = num / 100 % 10
			i++
		}
		if num >= 10 {
			result[i] = num / 10 % 10
			i++
		}
		result[i] = num % 10
		i++

	}
	return result
}