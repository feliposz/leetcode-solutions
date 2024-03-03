func subStrHash(s string, p int, m int, k int, hashValue int) string {

    // computer the value for the one-past-last power
	pk := 1
	for i := 0; i < k; i++ {
		pk = pk * p % m
	}

	size := len(s)
	result := -999 // problem guarantees that answer always exists, so this value will be overwritten anyway
	hash := 0

    // this loop calculates a rolling hash starting from the last position and going backwards
	for i := size - 1; i >= 0; i-- {
		val_i := int(s[i] - 'a' + 1)
		hash = (hash*p + val_i) % m
		if i+k < size {
            // when the length of the substring is reached, we have to subtract the value of the one-past-last element
			val_ik := int(s[i+k] - 'a' + 1)
			hash = (hash - val_ik*pk%m + m) % m
		}
        //fmt.Println(i, hash, hashValue)
		if hash == hashValue {
			result = i
		}
	}
	return s[result : result+k]
}