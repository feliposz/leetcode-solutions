type MyCalendar struct {
	events [][]int
}

func Constructor() MyCalendar {
	return MyCalendar{}
}

func (this *MyCalendar) Book(start int, end int) bool {
	for _, event := range this.events {
		startEvent, endEvent := event[0], event[1]
		if start < endEvent && startEvent < end {
			return false
		}
	}
	this.events = append(this.events, []int{start, end})
	return true
}

/**
 * Your MyCalendar object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Book(start,end);
 */