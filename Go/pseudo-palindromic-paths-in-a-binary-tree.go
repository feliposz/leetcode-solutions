/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func pseudoPalindromicPaths (root *TreeNode) int {
    return countPPP(root, 0)
}

func countPPP(node *TreeNode, digits int) int {
    if node == nil {
        return 0
    }
    digits ^= 1 << node.Val
    if node.Left == nil && node.Right == nil {
        // found a leaf node, check if path digits can form a palindrome
        if digits & (digits - 1) == 0 {
            //fmt.Println(digits)
            return 1
        } else {
            return 0
        }
    }
    return countPPP(node.Left, digits) + countPPP(node.Right, digits)
}
