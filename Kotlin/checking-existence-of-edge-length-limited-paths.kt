class Solution {
    fun distanceLimitedPathsExist(n: Int, edgeList: Array<IntArray>, queries: Array<IntArray>): BooleanArray {
        val uf = UnionFind(n)

        edgeList.sortBy { edge -> edge[2] }

        val sortedQueriesWithIndices = queries.withIndex()
            .map { (index, query) -> query.plus(index) }
            .sortedBy { query -> query[2] }

        val ans = BooleanArray(queries.size)
        var edgeIndex = 0

        for ((p, q, limit, index) in sortedQueriesWithIndices) {
            while (edgeIndex < edgeList.size) {
                val (u, v, dist) = edgeList[edgeIndex]
                if (dist >= limit) {
                    break
                }
                uf.join(u, v)
                edgeIndex++
            }
            ans[index] = uf.areConnected(p, q)
        }

        return ans
    }
}

class UnionFind(n: Int) {
    var group = IntArray(n) { it }
    var rank = IntArray(n) { it }

    // find the group of node
    fun find(node: Int): Int {
        var node2 = node
        while (node2 != group[node2]) {
            node2 = group[node2]
        }
        return node2
    }

    // include both nodes in the same component
    fun join(node1: Int, node2: Int) {
        val g1 = find(node1)
        val g2 = find(node2)
        if (g1 != g2) {
            if (rank[g1] > rank[g2]) {
                group[g2] = g1
            } else if (rank[g1] > rank[g2]) {
                group[g1] = g2
            } else {
                group[g2] = g1
                rank[g1] += 1
            }
        }
    }

    // check if both nodes belong to the same component
    fun areConnected(node1: Int, node2: Int): Boolean {
        return find(node1) == find(node2)
    }
}