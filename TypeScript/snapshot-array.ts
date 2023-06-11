class SnapshotArray {
    arr: number[][]
    id: number = 0

    constructor(length: number) {
        this.arr = Array(length)
        for (let i = 0; i < length; i++) {
            this.arr[i] = [0]
        }
    }

    set(index: number, val: number): void {
        this.arr[index][this.id] = val
    }

    snap(): number {
        return this.id++
    }

    get(index: number, snap_id: number): number {
        for (let i = snap_id; i >= 0; i--) {
            if (this.arr[index][i] !== undefined) {
                return this.arr[index][i]
            }
        }
        return 0
    }
}

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * var obj = new SnapshotArray(length)
 * obj.set(index,val)
 * var param_2 = obj.snap()
 * var param_3 = obj.get(index,snap_id)
 */