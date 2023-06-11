function findNonMinOrMax(nums: number[]): number {
    if (nums.length < 3) {
        return -1
    }
    let lo = nums[0], hi = nums[0]
    for (const n of nums) {
        lo = Math.min(lo, n)
        hi = Math.max(hi, n)
    }
    for (const n of nums) {
        if (n > lo && n < hi) {
            return n
        }
    }
    return -1
};