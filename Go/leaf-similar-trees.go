/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func leafSimilar(root1 *TreeNode, root2 *TreeNode) bool {
    var leaves1, leaves2 []int
    findLeaves(root1, &leaves1)
    findLeaves(root2, &leaves2)
    return slices.Equal(leaves1, leaves2)
}

func findLeaves(node *TreeNode, leaves *[]int) {
    if node == nil {
        return
    }
    if node.Left == nil && node.Right == nil {
        *leaves = append(*leaves, node.Val)
    } else {
        findLeaves(node.Left, leaves)
        findLeaves(node.Right, leaves)
    }
}