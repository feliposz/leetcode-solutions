/**
 * @param {number} k
 * @param {number[]} nums
 */
var KthLargest = function(k, nums) {
    this.k = k
    this.nums = []
    nums.sort()
    for (const n of nums) {
        this.add(n)
    }
};

/** 
 * @param {number} val
 * @return {number}
 */
KthLargest.prototype.add = function(val) {
    let i = 0, j = this.nums.length - 1
    if (this.nums.length > 0 && val < this.nums[0]) {
        this.nums.unshift(val)
    } else if (this.nums.length == 0 || val >= this.nums[j]) {
        this.nums.push(val)
    } else {
        while (i <= j) {
            const mid = Math.floor((i + j) / 2)
            if (val < this.nums[mid])
                j = mid - 1
            else if (val > this.nums[mid])
                i = mid + 1
            else {
                i = j = mid
                break
            }
        }
        //console.log(`i=${i} n[i]=${this.nums[i]} j=${j} n[j]=${this.nums[j]}`)
        this.nums.splice(i, 0, val)
    }
    //console.log("Added", val, "Nums", this.nums)
    return this.nums[this.nums.length - this.k]
};

/** 
 * Your KthLargest object will be instantiated and called as such:
 * var obj = new KthLargest(k, nums)
 * var param_1 = obj.add(val)
 */