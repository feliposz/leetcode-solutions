function getAverages(nums: number[], k: number): number[] {
    const ans: number[] = Array(nums.length).fill(-1)
    let sum = 0
    for (let i = 0; i < k * 2 + 1; i++) {
        sum += nums[i]
    }
    for (let i = k; i < nums.length - k; i++) {
        ans[i] = Math.floor(sum / (2 * k + 1))
        sum = sum - nums[i - k] + nums[i + k + 1]
    }
    return ans
};