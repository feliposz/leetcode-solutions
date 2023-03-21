class Solution {
    fun numOfMinutes(n: Int, headID: Int, manager: IntArray, informTime: IntArray): Int {
        // create an array of lists   
        var hierarchy = Array<ArrayList<Int>>(n, {ArrayList<Int>()})

        // each bucket is a manager and the list is all his subordinates
        for ((i, m) in manager.withIndex()) {
            if (m < 0)
                continue
            hierarchy[m].add(i)
        }

        // starting from the head manager 
        // recursively sum the informTime for his subordinates        
        return calcTime(headID, hierarchy, informTime)
    }

    // add the max of the subordinate managers to the current manager time
    fun calcTime(id: Int, hierarchy: Array<ArrayList<Int>>, informTime: IntArray): Int {
        var maxTime = 0
        for (employee in hierarchy[id]) {
            val time = calcTime(employee, hierarchy, informTime)
            if (maxTime < time)
                maxTime = time
        }
        return informTime[id] + maxTime
    }
}