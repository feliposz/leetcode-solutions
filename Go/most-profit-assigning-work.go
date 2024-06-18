func maxProfitAssignment(difficulty []int, profit []int, worker []int) int {
    total := 0
    type job struct{d, p int}
    jobs := []*job{}
    for i, d := range difficulty {
        jobs = append(jobs, &job{d, profit[i]})
    }
    cmp := func (a, b *job) int {
        if a.d != b.d {
            return a.d - b.d
        }
        return b.p - a.p
    }
    slices.SortFunc(jobs, cmp)
    best := 0
    for i := range jobs {
        if jobs[i].p < best {
            jobs[i].p = best
        } else {
            best = jobs[i].p
        }        
    }
    for _, w := range worker {
        best := 0
        lo, hi := 0, len(jobs) - 1
        for lo <= hi {
            mid := (lo + hi) / 2
            if jobs[mid].d > w {
                hi = mid - 1
            } else {
                lo = mid + 1
                best = max(best, jobs[mid].p)
            }
        }
        total += best
    }

    return total
}