func maximumPrimeDifference(nums []int) int {
    left, right := 0, len(nums)-1
    for left < right {
        if isPrime(nums[left]) {
            break
        }
        left++
    }
    for left < right {
        if isPrime(nums[right]) {
            break
        }
        right--
    }
    return right - left
}

func isPrime(x int) bool {
    if x < 2 {
        return false
    }
    if x == 2 {
        return true
    }
    if x % 2 == 0 {
        return false
    }
    for d := 3; d * d <= x; d += 2 {
        if x % d == 0 {
            return false
        }
    }
    return true
}