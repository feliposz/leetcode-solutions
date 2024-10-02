func numOfSubarrays(arr []int, k int, threshold int) int {
    limit := threshold * k
    i := 0
    sum := 0
    for i < k - 1 {
        sum += arr[i]
        i++
    }
    count := 0
    for i < len(arr) {
        sum += arr[i]
        if sum >= limit {
            count++
        }
        sum -= arr[i-k+1]
        i++
    }
    return count
}