func validPath(n int, edges [][]int, source int, destination int) bool {
	if source == destination {
		return true
	}

	uf := NewUnionFindWithRank(n)

	for _, e := range edges {
		uf.Union(e[0], e[1])
	}

	return uf.AreConnected(source, destination)
}

type UnionFindWithRank struct {
	parent []int
	rank   []int
}

func NewUnionFindWithRank(n int) *UnionFindWithRank {
	parent := make([]int, n)
	rank := make([]int, n)
	for i := 0; i < n; i++ {
		parent[i] = i
		rank[i] = 1
	}
	return &UnionFindWithRank{parent, rank}
}

func (uf *UnionFindWithRank) Find(x int) int {
	if uf.parent[x] != x {
		uf.parent[x] = uf.Find(uf.parent[x])
	}
	return uf.parent[x]
}

func (uf *UnionFindWithRank) Union(x, y int) {
	x, y = uf.Find(x), uf.Find(y)
	if uf.rank[x] < uf.rank[y] {
		uf.parent[x] = y
	} else if uf.rank[x] > uf.rank[y] {
		uf.parent[y] = x
	} else {
		uf.parent[y] = x
		uf.rank[x]++
	}
}

func (uf *UnionFindWithRank) AreConnected(node1, node2 int) bool {
	return uf.Find(node1) == uf.Find(node2)
}