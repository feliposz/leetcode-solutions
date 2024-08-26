/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Children []*Node
 * }
 */

func postorder(root *Node) []int {
	return post(root, []int{})
}

func post(node *Node, values []int) []int {
	if node == nil {
		return values
	}
	for _, child := range node.Children {
		values = post(child, values)
	}
	values = append(values, node.Val)
	return values
}
