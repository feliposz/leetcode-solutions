/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func getDirections(root *TreeNode, startValue int, destValue int) string {
    startPath := pathTo(root, startValue, []byte{})
    destPath := pathTo(root, destValue, []byte{})
    i := 0
    for i < len(startPath) && i < len(destPath) && startPath[i] == destPath[i]{
        i++
    }
    startPath = startPath[i:]
    destPath = destPath[i:]
    return strings.Repeat("U", len(startPath)) + string(destPath)
}

func pathTo(root *TreeNode, target int, partial []byte) []byte {
    if root == nil {
        return nil
    }
    if root.Val == target {
        return slices.Clone(partial)
    }
    partial = append(partial, 'L')
    left := pathTo(root.Left, target, partial)
    if left != nil {
        return left
    }
    partial = partial[:len(partial)-1]
    partial = append(partial, 'R')
    right := pathTo(root.Right, target, partial)
    partial = partial[:len(partial)-1]
    return right
}