function nextGreatestLetter(letters: string[], target: string): string {
    let lo = 0, hi = letters.length - 1
    let ans = letters[0]
    while (lo <= hi) {
        const mid = Math.floor((lo + hi) / 2)
        if (target >= letters[mid]) {
            lo = mid + 1
        } else {
            ans = letters[mid]
            hi = mid - 1
        }
    }
    return ans
};