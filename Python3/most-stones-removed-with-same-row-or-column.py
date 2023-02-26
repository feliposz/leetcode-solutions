class Solution:
    def removeStones(self, stones: List[List[int]]) -> int:
        def dfs(i, j):
            points.discard((i, j))
            for y in rows[i]:
                if (i, y) in points:
                    dfs(i, y)
            for x in cols[j]:
                if (x, j) in points:
                    dfs(x, j)
        
        points = {(i, j) for i, j in stones}
        islands = 0
        rows = collections.defaultdict(list)
        cols = collections.defaultdict(list)

        for i, j in stones:
            rows[i].append(j)
            cols[j].append(i)

        for i, j in stones:
            if (i, j) in points:
                dfs(i, j)
                islands += 1

        return len(stones) - islands
