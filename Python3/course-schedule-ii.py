class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        graph = defaultdict(list)
        indegree = [0] * numCourses
        queue = deque()
        ans = []

        # make adjacency graph and calculate degree of every node
        for next, pre in prerequisites:
            graph[pre].append(next)
            indegree[next] += 1

        # enqueue courses that have no prereq (indegree is 0)
        for i in range(numCourses):
            if indegree[i] == 0:
                queue.append(i)

        # process each course in the queue as it appears
        while queue:
            current = queue.popleft()
            ans.append(current)
            for nextCourse in graph[current]:
                # when a course appears, decrement its degree (remove prereq)
                indegree[nextCourse] -= 1
                # when it reaches zero, it means all prereqs have been met and it can be enqueued
                if indegree[nextCourse] == 0:
                    queue.append(nextCourse)

        # check if all the courses have been processed
        if len(ans) != numCourses:
            ans = []

        return ans


    
