/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func countPairs(root *TreeNode, distance int) int {
	adj := map[*TreeNode][]*TreeNode{}
	leaves := map[*TreeNode]bool{}
	buildAdjAndLeaves(root, adj, leaves)
	// fmt.Println("adj", adj)
	// fmt.Println("leaves", leaves)
	pairs := 0
	for src := range leaves {
		visited := map[*TreeNode]bool{}
		queue := []entry{{src, 0}}
		for len(queue) > 0 {
			front := queue[0]
			if front.dist > distance {
				break
			}
			if front.node != src && leaves[front.node] {
				pairs++
			}
			queue = queue[1:]
			visited[front.node] = true
			for _, next := range adj[front.node] {
				if !visited[next] {
					queue = append(queue, entry{next, front.dist + 1})
				}
			}
		}
	}
	return pairs / 2
}

func buildAdjAndLeaves(node *TreeNode, adj map[*TreeNode][]*TreeNode, leaves map[*TreeNode]bool) {
	if node.Left == nil && node.Right == nil {
		leaves[node] = true
		return
	}
	if node.Left != nil {
		adj[node] = append(adj[node], node.Left)
		adj[node.Left] = append(adj[node.Left], node)
		buildAdjAndLeaves(node.Left, adj, leaves)
	}
	if node.Right != nil {
		adj[node] = append(adj[node], node.Right)
		adj[node.Right] = append(adj[node.Right], node)
		buildAdjAndLeaves(node.Right, adj, leaves)
	}
}

type entry struct {
	node *TreeNode
	dist int
}
