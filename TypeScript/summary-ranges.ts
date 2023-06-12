function summaryRanges(nums: number[]): string[] {
    const ans = []
    let start = nums[0]
    for (let i = 1; i <= nums.length; i++) {
        if (i == nums.length || nums[i] - nums[i-1] > 1) {
            const end = nums[i-1]
            if (start == end) {
                ans.push(`${start}`)
            } else {
                ans.push(`${start}->${end}`)
            }
            start = nums[i]
        }
    }
    return ans
};