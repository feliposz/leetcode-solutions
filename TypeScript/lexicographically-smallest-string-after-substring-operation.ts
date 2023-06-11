function smallestString(s: string): string {
    const cs = s.split('')
    const n = cs.length
    let i = 0
    while (i < n && cs[i] === 'a') {
        i++
    }
    if (i === n) {
        cs[n-1] = 'z'
    } else {
        while (i < n && cs[i] !== 'a') {
            cs[i] = String.fromCharCode(cs[i].charCodeAt(0) - 1)
            i++
        }
    }
    return cs.join('')
};