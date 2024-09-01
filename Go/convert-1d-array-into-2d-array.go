func construct2DArray(original []int, m int, n int) [][]int {
	if len(original) != m*n {
		return [][]int{}
	}
	arr := make([][]int, m)
	for i := range arr {
		arr[i] = make([]int, n)
		for j := range arr[i] {
			arr[i][j] = original[i*n+j]
		}
	}
	return arr
}