/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func createBinaryTree(descriptions [][]int) *TreeNode {
    m := map[int]*TreeNode{}
    isChild := map[int]bool{}
    for _, d := range descriptions {
        p, c, l := d[0], d[1], d[2]
        if _, found := m[p]; !found {
            m[p] = &TreeNode{p, nil, nil}
        }
        if _, found := m[c]; !found {
            m[c] = &TreeNode{c, nil, nil}
        }
        isChild[c] = true
        if l == 1 {
            m[p].Left = m[c]
        } else {
            m[p].Right = m[c]
        }
    }
    for _, n := range m {
        if isChild[n.Val] == false {
            return n
        }
    }
    return nil
}