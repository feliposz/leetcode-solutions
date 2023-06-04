function numOfMinutes(n: number, headID: number, manager: number[], informTime: number[]): number {
    const hierarchy: number[][] = Array(n)
    for (let i = 0; i < n; i++) {
        hierarchy[i] = []
    }
    for (let i = 0; i < n; i++) {
        const m = manager[i]
        if (m !== -1) {
            hierarchy[m].push(i)
        }
    }
    const calcTime = (manager) => {
        let maxTime = 0
        for (const sub of hierarchy[manager]) {
            maxTime = Math.max(maxTime, calcTime(sub))
        }
        return maxTime + informTime[manager]
    }
    return calcTime(headID)
};