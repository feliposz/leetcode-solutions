function findValueOfPartition(nums: number[]): number {
    nums.sort((a, b) => a - b)
    let minDiff = nums[nums.length - 1] - nums[0]
    for (let i = 1; i < nums.length; i++) {
        const diff = nums[i] - nums[i-1]
        if (minDiff > diff) {
            minDiff = diff
        }
    }
    return minDiff
};