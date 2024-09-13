func xorQueries(arr []int, queries [][]int) []int {
	x := make([]int, len(arr))
	x[0] = arr[0]
	for i := 1; i < len(arr); i++ {
		x[i] = arr[i] ^ x[i-1]
	}
	res := make([]int, len(queries))
	for i, q := range queries {
		left, right := q[0], q[1]
		if left == 0 {
			res[i] = x[right]
		} else {
			res[i] = x[left-1] ^ x[right]
		}
	}
	return res
}