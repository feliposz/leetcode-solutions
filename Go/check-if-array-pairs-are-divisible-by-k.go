func canArrange(arr []int, k int) bool {
	freq := map[int]int{}
	for _, x := range arr {
		freq[((x%k)+k)%k]++
	}
	for i := 0; i < k; i++ {
		if i == 0 || i == k-i {
			if freq[i]%2 != 0 {
				return false
			}
		} else if freq[i] != freq[k-i] {
			return false
		}
	}
	return true
}