/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func buildTree(preorder []int, inorder []int) *TreeNode {
    if len(preorder) == 0 {
        return nil
    }
    split := slices.Index(inorder, preorder[0])
    return &TreeNode{
        preorder[0],
        buildTree(preorder[1:split+1], inorder[:split]),
        buildTree(preorder[split+1:], inorder[split+1:]),
    }
}