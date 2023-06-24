function longestArithSeqLength(nums: number[]): number {
    function subSeq(i: number, j: number) {
        const delta = nums[j] - nums[i]
        let length = 1
        let prev = nums[i]
        for (let k = j; k < nums.length; k++) {
            if (nums[k] - prev === delta) {
                length++
                prev = nums[k]
            }
        }
        return length
    }
    let maxLen = 0
    for (let i = 0; i < nums.length; i++) {
        for (let j = i + 1; j < nums.length; j++) {
            const len = subSeq(i, j)
            if (maxLen < len) {
                maxLen = len
            }
        }
    }
    return maxLen
};