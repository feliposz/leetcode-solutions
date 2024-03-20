type RecentCounter struct {
    requests []int
}


func Constructor() RecentCounter {
    return RecentCounter{make([]int, 0)}
}


func (this *RecentCounter) Ping(t int) int {
    if len(this.requests) > 0 && this.requests[0] < t - 3000 {
        removeIndex, _ := slices.BinarySearch(this.requests, t - 3000)
        this.requests = this.requests[removeIndex:]
    }
    this.requests = append(this.requests, t)
    return len(this.requests)
}


/**
 * Your RecentCounter object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Ping(t);
 */