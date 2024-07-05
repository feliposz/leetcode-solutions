/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func nodesBetweenCriticalPoints(head *ListNode) []int {
	minDist, maxDist := -1, -1
	criticalPoints := []int{}
	var prev *ListNode
	curr := head
	for pos := 0; curr != nil; pos++ {
		if prev != nil && curr.Next != nil {
			if curr.Val > prev.Val && curr.Val > curr.Next.Val {
				criticalPoints = append(criticalPoints, pos)
			} else if curr.Val < prev.Val && curr.Val < curr.Next.Val {
				criticalPoints = append(criticalPoints, pos)
			}
		}
		prev = curr
		curr = curr.Next
	}
	fmt.Println(criticalPoints)
	for i := 1; i < len(criticalPoints); i++ {
		dist := criticalPoints[i] - criticalPoints[i-1]
		if minDist == -1 {
			minDist = dist
		} else {
			minDist = min(minDist, dist)
		}
	}
	if len(criticalPoints) > 1 {
		maxDist = criticalPoints[len(criticalPoints)-1] - criticalPoints[0]
	}
	return []int{minDist, maxDist}
}