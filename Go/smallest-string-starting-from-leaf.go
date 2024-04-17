/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

var result string
var tmp [8500]byte

func smallestFromLeaf(root *TreeNode) string {
    result = "~"
    search(root, len(tmp)-1)
    return result
}

func search(node *TreeNode, depth int) {
    if node == nil {
        return
    }
    tmp[depth] = byte(node.Val + 'a')
    if node.Left == nil && node.Right == nil {
        t := string(tmp[depth:len(tmp)])
        if result > t {
            result = t
        }
    }
    search(node.Left, depth-1)
    search(node.Right, depth-1)
}