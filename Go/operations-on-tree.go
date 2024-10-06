type LockingTree struct {
	Nodes []*Node
}

type Node struct {
	Val      int
	User     int
	Parent   *Node
	Children []*Node
}

func Constructor(parent []int) LockingTree {
	t := LockingTree{}
	t.Nodes = make([]*Node, len(parent))
	for i := range parent {
		t.Nodes[i] = &Node{i, 0, nil, nil}
	}
	for i, p := range parent {
		if p != -1 {
			t.Nodes[p].Children = append(t.Nodes[p].Children, t.Nodes[i])
			t.Nodes[i].Parent = t.Nodes[p]
		}
	}
	return t
}

func (this *LockingTree) Lock(num int, user int) bool {
	if this.Nodes[num].User != 0 {
		return false
	}
	this.Nodes[num].User = user
	return true
}

func (this *LockingTree) Unlock(num int, user int) bool {
	if this.Nodes[num].User != user {
		return false
	}
    this.Nodes[num].User = 0
	return true
}

func (this *LockingTree) Upgrade(num int, user int) bool {
	if this.Nodes[num].User != 0 {
		return false
	}
	n := this.Nodes[num].Parent
	for n != nil {
		if n.User != 0 {
			return false
		}
		n = n.Parent
	}
	if hasLockedDescendant(this.Nodes[num]) {
		unlockDescendants(this.Nodes[num])
		this.Nodes[num].User = user
		return true
	}
	return false
}

func hasLockedDescendant(node *Node) bool {
	if node == nil {
		return false
	}
	for _, c := range node.Children {
		if c.User != 0 || hasLockedDescendant(c) {
			return true
		}
	}
	return false
}

func unlockDescendants(node *Node) {
	if node == nil {
		return
	}
	for _, c := range node.Children {
		c.User = 0
		unlockDescendants(c)
	}
}

/**
 * Your LockingTree object will be instantiated and called as such:
 * obj := Constructor(parent);
 * param_1 := obj.Lock(num,user);
 * param_2 := obj.Unlock(num,user);
 * param_3 := obj.Upgrade(num,user);
 */