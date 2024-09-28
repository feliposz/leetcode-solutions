type MyCircularDeque struct {
	queue []int
	front int
	last  int
	used  int
}

func Constructor(k int) MyCircularDeque {
	return MyCircularDeque{make([]int, k), 0, k - 1, 0}
}

func (this *MyCircularDeque) pos(i int) int {
	return (i + len(this.queue)) % len(this.queue)
}

func (this *MyCircularDeque) InsertFront(value int) bool {
	if !this.IsFull() {
		this.front = this.pos(this.front - 1)
		this.queue[this.front] = value
		this.used++
		return true
	}
	return false
}

func (this *MyCircularDeque) InsertLast(value int) bool {
	if !this.IsFull() {
		this.last = this.pos(this.last + 1)
		this.queue[this.last] = value
		this.used++
		return true
	}
	return false
}

func (this *MyCircularDeque) DeleteFront() bool {
	if !this.IsEmpty() {
		this.used--
		this.front = this.pos(this.front + 1)
		return true
	}
	return false
}

func (this *MyCircularDeque) DeleteLast() bool {
	if !this.IsEmpty() {
		this.used--
		this.last = this.pos(this.last - 1)
		return true
	}
	return false
}

func (this *MyCircularDeque) GetFront() int {
	if this.IsEmpty() {
		return -1
	}
	return this.queue[this.front]
}

func (this *MyCircularDeque) GetRear() int {
	if this.IsEmpty() {
		return -1
	}
	return this.queue[this.last]
}

func (this *MyCircularDeque) IsEmpty() bool {
	return this.used == 0
}

func (this *MyCircularDeque) IsFull() bool {
	return this.used == len(this.queue)
}

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * obj := Constructor(k);
 * param_1 := obj.InsertFront(value);
 * param_2 := obj.InsertLast(value);
 * param_3 := obj.DeleteFront();
 * param_4 := obj.DeleteLast();
 * param_5 := obj.GetFront();
 * param_6 := obj.GetRear();
 * param_7 := obj.IsEmpty();
 * param_8 := obj.IsFull();
 */