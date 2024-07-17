/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func delNodes(root *TreeNode, to_delete []int) []*TreeNode {
    forest := []*TreeNode{}
    root = helper(root, to_delete, &forest)
    if root != nil {
        forest = append(forest, root)
    }
    return forest
}

func helper(root *TreeNode, to_delete []int, forest *[]*TreeNode) *TreeNode {
    if root == nil {
        return nil
    }
    root.Left = helper(root.Left, to_delete, forest)
    root.Right = helper(root.Right, to_delete, forest)
    for _, val := range to_delete {
        if root.Val == val {
            if root.Left != nil {
                *forest = append(*forest, root.Left)
            }
            if root.Right != nil {
                *forest = append(*forest, root.Right)
            }
            return nil
        }
    }
    return root
}