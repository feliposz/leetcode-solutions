function maxValue(n: number, index: number, maxSum: number): number {
    
    function arithmeticSequenceSum(first: number, last: number, count: number): number {
        return Math.floor((first + last) * count / 2)
    }

    function getSum(value: number): number {
        let sum = 0
        if (value > index) {
            sum += arithmeticSequenceSum(value - index, value, index + 1)
        } else {
            const countOnes = index - value + 1
            sum += arithmeticSequenceSum(1, value, value) + countOnes
        }
        if (value >= n - index) {
            sum += arithmeticSequenceSum(value, value - n + 1 + index, n - index)
        } else {
            const countOnes = n - index - value
            sum += arithmeticSequenceSum(1, value, value) + countOnes
        }
        return sum - value
    }

    let lo = 1, hi = maxSum
    let ans = 1
    while (lo <= hi) {
        const mid = Math.floor((lo + hi) / 2)
        const sum = getSum(mid)
        if (sum <= maxSum) {
            ans = mid
            lo = mid + 1
        } else {
            hi = mid - 1
        }
    }
    return ans
};