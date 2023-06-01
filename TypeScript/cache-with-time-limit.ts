class TimeLimitedCache {
    store: { [k: number]: { value: number, timeout: ReturnType<typeof setTimeout> } }

    constructor() {
        this.store = {}
    }

    set(key: number, value: number, duration: number): boolean {
        const unexpiredKeyExisted = (key in this.store) 
        if (unexpiredKeyExisted) {
            clearTimeout(this.store[key].timeout)
        }
        this.store[key] = { value: value, timeout: setTimeout(() => delete this.store[key], duration) }
        return unexpiredKeyExisted
    }

    get(key: number): number {
        if (key in this.store)
            return this.store[key].value
        return -1
    }

	count(): number {
        return Object.keys(this.store).length
    }
}

/**
 * Your TimeLimitedCache object will be instantiated and called as such:
 * var obj = new TimeLimitedCache()
 * obj.set(1, 42, 1000); // false
 * obj.get(1) // 42
 * obj.count() // 1
 */