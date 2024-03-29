func countSubarrays(nums []int, k int) int64 {
    result := int64(0)

    maxCount := 0
    maxElement := nums[0]
    for _, num := range nums {
        if maxElement < num {
            maxElement = num
            maxCount = 1
        } else if maxElement == num {
            maxCount++
        }
    }

    if maxCount < k {
        return 0
    }
    
    // O(n^2)
    // for i := range nums {
    //     maxCount := 0 
    //     for j := i; j < len(nums); j++ {
    //         if nums[j] == maxElement {
    //             maxCount++
    //         }
    //         if maxCount >= k {
    //             result++
    //         }
    //     }
    // }

    start := 0
    maxCount = 0
    for _, num := range nums {
        if num == maxElement {
            maxCount++
        }
        for maxCount >= k {
            if nums[start] == maxElement {
                maxCount--
            }
            start++
        }
        result += int64(start)
    }

    return result
        
}