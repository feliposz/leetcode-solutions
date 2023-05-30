class MyHashSet {
    table: number[][]
    size: number

    constructor() {
        this.size = 1000
        this.table = Array(this.size)
        for (let i = 0; i < this.size; i++) {
            this.table[i] = []
        }
    }

    hash(key: number): number {
        return Math.floor(key * 1361981) % this.size
    }

    bucketAndIndex(key: number): [number, number] {
        const bucket = this.hash(key)
        return [bucket, this.table[bucket].indexOf(key)]
    }

    add(key: number): void {
        const [bucket, index] = this.bucketAndIndex(key)
        if (index === -1) {
            this.table[bucket].push(key)
        }
    }

    remove(key: number): void {
        const [bucket, index] = this.bucketAndIndex(key)
        if (index !== -1) {
            this.table[bucket].splice(index, 1)
        }
    }

    contains(key: number): boolean {
        const [bucket, index] = this.bucketAndIndex(key)
        return index !== -1
    }
}

/**
 * Your MyHashSet object will be instantiated and called as such:
 * var obj = new MyHashSet()
 * obj.add(key)
 * obj.remove(key)
 * var param_3 = obj.contains(key)
 */