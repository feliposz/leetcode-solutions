class Solution {
    fun numSimilarGroups(strs: Array<String>): Int {
        val n = strs.size
        val sim: Array<Array<Int>> = Array(n, { Array(n, {0}) })
        for (i in 0 until n) {
            for (j in 0 until n) {
                if (i == j || isSimilar(strs[i], strs[j])) {
                    sim[i][j] = -1
                }
            }
        }
        var group = 0
        for (i in 0 until n) {
            for (j in 0 until n) {
                if (sim[i][j] == -1) {
                    fillGroup(sim, i, j, ++group)
                }
            }
        }
        print2d(sim)
        return group
    }

    fun fillGroup(mat: Array<Array<Int>>, i: Int, j: Int, group: Int) {
        val n = mat.size
        if (mat[i][j] == -1) {
            mat[i][j] = group
            for (x in 0 until n) {
                fillGroup(mat, i, x, group)
                fillGroup(mat, x, j, group)
            }
        }
    }

    fun isSimilar(a: String, b: String): Boolean {
        var diff = 0
        val n = a.length
        for (i in 0 until n) {
            if (a[i] != b[i]) {
                diff++
                if (diff > 2) {
                    return false
                }
            }
        }
        return true
    }

    fun print2d(sim: Array<Array<Int>>) {
        for (row in sim) {
            for (col in row) {
                print("$col ")
            }
            println()
        }
    }
}