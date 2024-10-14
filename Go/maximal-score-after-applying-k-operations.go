func maxKelements(nums []int, k int) int64 {
	pq := &IntHeap{}
	heap.Init(pq)
	for _, n := range nums {
		heap.Push(pq, n)
	}
	ans := int64(0)
	for k > 0 {
		n := int64(heap.Pop(pq).(int))
		ans += n
		heap.Push(pq, int(math.Ceil(float64(n)/3.0)))
		k--
	}
	return ans
}

type IntHeap []int

func (h IntHeap) Len() int           { return len(h) }
func (h IntHeap) Less(i, j int) bool { return h[i] > h[j] }
func (h IntHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *IntHeap) Push(x any) {
	*h = append(*h, x.(int))
}

func (h *IntHeap) Pop() any {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}
