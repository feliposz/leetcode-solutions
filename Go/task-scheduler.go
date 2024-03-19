func leastInterval(tasks []byte, n int) int {
    var taskCount, coolDown [26]int
    for _, t := range tasks {
        taskCount[t - 'A']++
    }
    cost := 0
    hasTasks := true
    for hasTasks {
        hasTasks = false
        var maxTask, maxCount int
        for task, count := range taskCount {
            if coolDown[task] <= 0 && count > maxCount {
                maxTask, maxCount = task, count
            }
            if count > 0 {
                hasTasks = true
            }
        }
        for task, countDown := range coolDown {
            if countDown > 0 {
                coolDown[task]--
            }
        }
        if maxCount > 0 {
            taskCount[maxTask]--
            coolDown[maxTask] = n
        }
        if hasTasks {
            cost++
        }
    }
    return cost
}