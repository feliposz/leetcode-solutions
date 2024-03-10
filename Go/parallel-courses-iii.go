// With cache

func minimumTime(n int, relations [][]int, time []int) int {
    dependencies := make([][]int, n)
    for _, r := range relations {
        prevCourse, nextCourse := r[0]-1, r[1]-1
        if dependencies[nextCourse] == nil {
            dependencies[nextCourse] = make([]int, 0)
        }
        dependencies[nextCourse] = append(dependencies[nextCourse], prevCourse)
    }

    courseTimeCache := make([]int, n)

    maxTime := 0
    for course := 0; course < n; course++ {
        time := courseTime(course, dependencies, time, courseTimeCache)
        maxTime = max(time, maxTime)
    }
    return maxTime
}

func courseTime(course int, dependencies [][]int, time []int, courseTimeCache []int) int {
    if courseTimeCache[course] != 0 {
        return courseTimeCache[course]
    }
    currTime := time[course]
    maxDepTime := 0
    for _, dep := range dependencies[course] {
        depTime := courseTime(dep, dependencies, time, courseTimeCache)
        maxDepTime = max(depTime, maxDepTime)
    }
    courseTimeCache[course] = currTime + maxDepTime
    return courseTimeCache[course]
}