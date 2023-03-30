class MyCalendar() {

    val events = arrayListOf<Pair<Int,Int>>()

    fun book(start: Int, end: Int): Boolean {
        for ((eventStart, eventEnd) in events) {
            if ((start < eventEnd) && (eventStart < end)) {
                return false
            }
        }
        events.add(Pair(start, end))
        //println(events)
        return true
    }

}

/**
 * Your MyCalendar object will be instantiated and called as such:
 * var obj = MyCalendar()
 * var param_1 = obj.book(start,end)
 */