type Callback = (...args: any[]) => any;
type Subscription = {
    unsubscribe: () => void
}

class EventEmitter {
    events = new Map<string, Callback[]>()

    subscribe(eventName: string, callback: Callback): Subscription {
        if (!this.events.has(eventName)) {
            this.events.set(eventName, [])
        }
        this.events.get(eventName).push(callback)
        return {
            unsubscribe: () => {
                const e = this.events.get(eventName)
                if (e) {
                    const i = e.indexOf(callback)
                    if (i >= 0) {
                        e.splice(i, 1)
                    }
                }
            }
        };
    }

    emit(eventName: string, args: any[] = []): any {
        const results = []
        if (this.events.has(eventName)) {
            for (const callback of this.events.get(eventName)) {
                results.push(callback(...args))
            }
        }
        return results
    }
}

/**
 * const emitter = new EventEmitter();
 *
 * // Subscribe to the onClick event with onClickCallback
 * function onClickCallback() { return 99 }
 * const sub = emitter.subscribe('onClick', onClickCallback);
 *
 * emitter.emit('onClick'); // [99]
 * sub.unsubscribe(); // undefined
 * emitter.emit('onClick'); // []
 */