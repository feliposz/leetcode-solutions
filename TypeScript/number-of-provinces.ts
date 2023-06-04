function findCircleNum(isConnected: number[][]): number {
    const n = isConnected.length
    const uf = new UnionFind(n)
    let components = n
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            if (isConnected[i][j]) {
                if (uf.find(i) != uf.find(j)) {
                    components--
                    uf.union(i, j)
                }
            }
        }
    }
    return components
};

class UnionFind {
    parent: number[]
    rank: number[]

    constructor(public n: number) {
        this.parent = Array(n)
        this.rank = Array(n)
        for (let i = 0; i < n; i++) {
            this.parent[i] = i
            this.rank[i] = 0
        }
    }

    union(x: number, y: number): void {
        const xp = this.find(x)
        const yp = this.find(y)
        if (this.rank[xp] < this.rank[yp]) {
            this.parent[xp] = yp
        } else if (this.rank[xp] > this.rank[yp]) {
            this.parent[yp] = xp
        } else {
            this.parent[yp] = xp
            this.rank[xp]++
        }
    }

    find(x: number): number {
        if (this.parent[x] != x) {
            this.parent[x] = this.find(this.parent[x])
        }
        return this.parent[x]
    }
}