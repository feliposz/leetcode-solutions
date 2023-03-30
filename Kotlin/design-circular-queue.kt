class MyCircularQueue(val k: Int) {

    private var queue = IntArray(k)
    private var front = 0
    private var rear = 0
    private var size = 0

    private fun normalize(index: Int) = index % k
    private fun advance(index: Int) = normalize(index + 1)
    private fun prev(index: Int) = normalize(index - 1 + k)

    fun enQueue(value: Int): Boolean {
        if (isFull())
            return false
        queue[rear] = value
        rear = advance(rear)
        size++
        return true
    }

    fun deQueue(): Boolean {
        if (isEmpty())
            return false
        front = advance(front)
        size--
        return true
    }

    fun Front(): Int {
        if (isEmpty())
            return -1
        return queue[front]
    }

    fun Rear(): Int {
        if (isEmpty())
            return -1
        return queue[prev(rear)]
    }

    fun isEmpty(): Boolean {
        return size == 0
    }

    fun isFull(): Boolean {
        return size == k
    }

}

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * var obj = MyCircularQueue(k)
 * var param_1 = obj.enQueue(value)
 * var param_2 = obj.deQueue()
 * var param_3 = obj.Front()
 * var param_4 = obj.Rear()
 * var param_5 = obj.isEmpty()
 * var param_6 = obj.isFull()
 */