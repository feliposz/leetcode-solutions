func sumPrefixScores(words []string) []int {
	trie := &Trie{}
	for _, w := range words {
		trie.Insert(w)
	}
	ans := make([]int, len(words))
	for i, w := range words {
		ans[i] = trie.Count(w)
	}
	return ans
}

type Trie struct {
	children [26]*Trie
	count    int
}

func (this *Trie) Insert(word string) {
	t := this
	for _, c := range []byte(word) {
		c = c - 'a'
		if t.children[c] == nil {
			t.children[c] = &Trie{}
		}
		t.children[c].count++
		t = t.children[c]
	}
}

func (this *Trie) Count(prefix string) int {
	t := this
	ans := 0
	for _, c := range []byte(prefix) {
		c = c - 'a'
		ans += t.children[c].count
		t = t.children[c]
	}
	return ans
}
