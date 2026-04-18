/**
 * @param {number[]} nums
 * @param {number[]} queries
 * @return {number[]}
 */
var solveQueries = function (nums, queries) {
    const answer = new Array(queries.length).fill(-1)
    const m = new Map()
    for (let i = 0; i < nums.length; i++) {
        const n = nums[i]
        if (!m.has(n)) {
            m.set(n, new Array())
        }
        m.get(n).push(i)
    }
    for (let i = 0; i < queries.length; i++) {
        const q = queries[i]
        const s = m.get(nums[q])
        if (s.length < 2) continue
        const qidx = binarySearch(s, q)
        const left = s[(qidx - 1 + s.length) % s.length]
        const right = s[(qidx + 1) % s.length]
        answer[i] = Math.min((q - left + nums.length) % nums.length,
            (right - q + nums.length) % nums.length)
    }
    return answer
};

function binarySearch(arr, target) {
    let left = 0,
        right = arr.length;
    while (left < right) {
        const mid = Math.floor((left + right) / 2);
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}