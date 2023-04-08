/**
 * Definition for a Node.
 * class Node(var `val`: Int) {
 *     var neighbors: ArrayList<Node?> = ArrayList<Node?>()
 * }
 */

class Solution {
    
    val cloned = mutableMapOf<Node,Node>()
    
    fun cloneGraph(node: Node?): Node? {
        if (node == null) {
            return null
        }        
        if (cloned.contains(node)) {
            return cloned[node]
        }
        //println("Cloning $node")
        val copy = Node(node.`val`)
        cloned[node] = copy
        for (neighbor in node.neighbors) {
            val neighborCopy = cloneGraph(neighbor)
            copy.neighbors.add(neighborCopy)
        }        
        return copy
    }
}