type MyCalendarTwo struct {
	events map[int]int
}

func Constructor() MyCalendarTwo {
	return MyCalendarTwo{
		map[int]int{},
	}
}

func (this *MyCalendarTwo) Book(start int, end int) bool {
	this.events[start]++
	this.events[end]--
	times := make([]int, 0, len(this.events))
	for time, _ := range this.events {
		times = append(times, time)
	}
	slices.Sort(times)
	bookings := 0
	for _, time := range times {
		bookings += this.events[time]
		if bookings >= 3 {
			this.events[start]--
			this.events[end]++
			if this.events[start] == 0 {
				delete(this.events, start)
			}
			if this.events[end] == 0 {
				delete(this.events, end)
			}
			return false
		}
	}
	return true
}
