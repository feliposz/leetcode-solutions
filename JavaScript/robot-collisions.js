/**
 * @param {number[]} positions
 * @param {number[]} healths
 * @param {string} directions
 * @return {number[]}
 */
var survivedRobotsHealths = function (positions, healths, directions) {
    const robots = []
    for (let i = 0; i < positions.length; i++) {
        robots.push({
            id: i,
            pos: positions[i],
            health: healths[i],
            dir: directions[i] === 'L' ? -1 : 1,
        })
    }
    robots.sort((a, b) => a.pos - b.pos)

    const stack = []
    for (let i = 0; i < robots.length; i++) {
        if (robots[i].dir === 1) {
            stack.push(i)
            continue
        }
        while (stack.length > 0) {
            const top = stack.pop()
            if (robots[top].health > robots[i].health) {
                robots[top].health--
                robots[i].health = 0
                if (robots[top].health > 0) {
                    stack.push(top)
                    break
                }
            } else if (robots[top].health < robots[i].health) {
                robots[i].health--
                robots[top].health = 0
                if (robots[i].health == 0) {
                    break
                }
            } else {
                robots[i].health = 0
                robots[top].health = 0
                break
            }
        }
    }
    robots.sort((a, b) => a.id - b.id)
    return robots.filter(r => r.health > 0).map(r => r.health)
};