/**
 * Definition for a Node.
 * class Node(var `val`: Int) {
 *     var children: List<Node?> = listOf()
 * }
 */

class Solution {
    fun levelOrder(root: Node?): List<List<Int>> {
        // level order traversal of tree

        // declare queue of nodes + level
        val q = ArrayDeque<Pair<Node?, Int>>()

        // declare mutable list of mutable lists
        val lol = MutableList<MutableList<Int>>(0, {MutableList<Int>(0, {0})})

        // enqueue root node (level = 0)
        if (root != null)
            q.addLast(Pair(root, 0))

        // while q is not empty
        while (q.size > 0) {
            // pick node from q along with level
            val (node, level) = q.first()

            if (node == null)
                continue

            // remove front of queue
            q.removeFirst()

            // add to list on given level (grow list as needed)
            if (level > lol.size - 1) {
                lol.add(MutableList(0, {0}))
            }
            lol[level].add(node.`val`)

            // enqueue all its children on level + 1
            for (child in node.children) {
                q.addLast(Pair(child, level + 1))
            }
        }

        // convert result to immutable list
        return lol.toList()
    }
}