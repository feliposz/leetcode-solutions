import (
	pq "github.com/emirpasic/gods/queues/priorityqueue"
)

func nthUglyNumber(n int) int {
	heap := pq.NewWith(func(a, b any) int {
		return a.(int) - b.(int)
	})
	set := map[int]bool{}
	ugly := -1
	heap.Enqueue(1)
	set[1] = true
	factors := []int{2, 3, 5}
	for i := 0; i < n; i++ {
		top, _ := heap.Dequeue()
		ugly = top.(int)
		for _, factor := range factors {
			if !set[ugly*factor] {
				heap.Enqueue(ugly * factor)
				set[ugly*factor] = true
			}
		}
	}
	return ugly
}
