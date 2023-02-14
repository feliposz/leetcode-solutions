class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        counter = defaultdict(lambda: 0)
        Max = 0
        MaxCount = 0
        for t in tasks:
            counter[t] += 1
            if Max == counter[t]:
                MaxCount += 1
            elif Max < counter[t]:
                Max = counter[t]
                MaxCount = 1
        
        partCount = Max - 1
        partLength = n - (MaxCount - 1)
        emptySlots = partCount * partLength
        availableTasks = len(tasks) - Max * MaxCount
        idles = max(0, emptySlots - availableTasks)
        
        return len(tasks) + idles