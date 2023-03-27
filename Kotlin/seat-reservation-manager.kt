class SeatManager(n: Int) {

    val freeSeats = PriorityQueue<Int>()

    init {
        (1..n).forEach { freeSeats.add(it) }
    }

    fun reserve(): Int {
        return freeSeats.poll()
    }

    fun unreserve(seatNumber: Int) {
        freeSeats.add(seatNumber)
    }

}

/**
 * Your SeatManager object will be instantiated and called as such:
 * var obj = SeatManager(n)
 * var param_1 = obj.reserve()
 * obj.unreserve(seatNumber)
 */