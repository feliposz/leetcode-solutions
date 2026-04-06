/**
 * @param {number[]} commands
 * @param {number[][]} obstacles
 * @return {number}
 */
var robotSim = function (commands, obstacles) {
    let x = 0
    let y = 0
    let dx = 0
    let dy = 1
    let max = 0
    const o = new Set()
    for (const [xi, yi] of obstacles) {
        o.add(xi * 100000 + yi)
    }
    for (const cmd of commands) {
        if (cmd === -2) {
            [dx, dy] = [-dy, dx]
        } else if (cmd === -1) {
            [dx, dy] = [dy, -dx]
        } else {
            for (let i = 0; i < cmd; i++) {
                const xi = x + dx
                const yi = y + dy
                if (o.has(xi * 100000 + yi)) {
                    break
                }
                x = xi
                y = yi
            }
            max = Math.max(max, x * x + y * y)
        }
    }
    return max
};