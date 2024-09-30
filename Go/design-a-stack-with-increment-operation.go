type CustomStack struct {
	stack   []int
	size    int
}

func Constructor(maxSize int) CustomStack {
	return CustomStack{
		make([]int, maxSize),
		0,
	}
}

func (this *CustomStack) Push(x int) {
	if this.size >= len(this.stack) {
		return
	}
	this.stack[this.size] = x
	this.size++
}

func (this *CustomStack) Pop() int {
	if this.size <= 0 {
		return -1
	}
	this.size--
	top := this.stack[this.size]
	return top
}

func (this *CustomStack) Increment(k int, val int) {
	for i := 0; i < k && i < len(this.stack); i++ {
		this.stack[i] += val
	}
}

/**
 * Your CustomStack object will be instantiated and called as such:
 * obj := Constructor(maxSize);
 * obj.Push(x);
 * param_2 := obj.Pop();
 * obj.Increment(k,val);
 */