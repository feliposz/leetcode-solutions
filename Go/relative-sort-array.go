func relativeSortArray(arr1 []int, arr2 []int) []int {
	count := make([]int, 1001)
	for _, n := range arr1 {
		count[n]++
	}
    index := 0
    for _, n := range arr2 {
        size := count[n]
        for size > 0 {
            arr1[index] = n
            index++
            size--
        }
        count[n] = 0
    }
    for n, size := range count {
        for size > 0 {
            arr1[index] = n
            index++
            size--
        }
    }
	return arr1
}

func MAP_relativeSortArray(arr1 []int, arr2 []int) []int {
	order := map[int]int{}
	for i, n := range arr2 {
		order[n] = i
	}
	slices.SortFunc(arr1, func(a, b int) int {
		aOrder, aFound := order[a]
		bOrder, bFound := order[b]
		if aFound && bFound {
			return aOrder - bOrder
		} else if aFound {
			return -1
		} else if bFound {
			return 1
		}
		return a - b
	})
	return arr1
}