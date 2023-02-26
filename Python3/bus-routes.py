class Solution:
    def numBusesToDestination(self, routes: List[List[int]], source: int, target: int) -> int:

        # already at target
        if source == target:
            return 0
        
        # for every stop, keep track of buses that stop there
        stopBoard = {}

        for bus, stops in enumerate(routes):
            for stop in stops:
                if stop not in stopBoard:
                    stopBoard[stop] = [bus]
                else:
                    stopBoard[stop].append(bus)

        queue = deque([source])
        visited = set()

        count = 0

        while queue:

            count += 1

            preNumStops = len(queue)
            for _ in range(preNumStops):
                currentStop = queue.popleft()
                for bus in stopBoard[currentStop]:
                    if bus in visited:
                        continue
                    visited.add(bus)
                    for stop in routes[bus]:
                        if stop == target:
                            return count
                        queue.append(stop)
        
        return -1
