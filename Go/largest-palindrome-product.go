func largestPalindrome(n int) int {
	if n == 1 {
        return 9
    }

    low := int64(1)
	for n > 1 {
		low *= 10
		n--
	}
	high := low*10 - 1

	for i := high; i >= low; i-- {        
		left := i
        right := int64(0)
        for temp := left; temp > 0; temp /= 10 {
            right = right*10 + temp%10
            left *= 10
        }
        palindrom := left + right
        
        for j := high; j >= low; j-- {
			k := palindrom / j
			if (k > j) {
                break
			}
            if palindrom % j == 0 {
                return int(palindrom % 1337)
            }
		}
	}
	return -1
}

func isPalindrome(n int64) bool {
	return n == reversed(n)
}

func reversed(n int64) int64 {
	result := int64(0)
	for n > 0 {
		result = result*10 + n%10
		n /= 10
	}
	return result
}