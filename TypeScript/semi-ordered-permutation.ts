function semiOrderedPermutation(nums: number[]): number {
    const n = nums.length
    if (nums[0] === 1 && nums[n-1] === n) {
        return 0
    }
    let count = 0
    while (nums[0] !== 1 || nums[n-1] !== n) {
        for (let i = 1; i < n; i++) {
            if (nums[i] === 1 || nums[i-1] === n) {
                const tmp = nums[i]
                nums[i] = nums[i-1]
                nums[i-1] = tmp
                count++
            }
        }
    }
    return count
};