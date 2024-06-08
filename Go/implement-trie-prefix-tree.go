type Trie struct {
	children [26]*Trie
	isWord   bool
}

func Constructor() Trie {
	return Trie{}
}

func (this *Trie) Insert(word string) {
	sz := len(word)
	if sz > 0 {
		c := word[0] - 'a'
		if this.children[c] == nil {
			trie := Constructor()
			this.children[c] = &trie
		}
		if sz == 1 {
			this.children[c].isWord = true
		}
		this.children[c].Insert(word[1:])
	}
}

func (this *Trie) Search(word string) bool {
	t := this
	for _, c := range []byte(word) {
		c = c - 'a'
		if t.children[c] != nil {
			t = t.children[c]
		} else {
			return false
		}
	}
	return t.isWord
}

func (this *Trie) StartsWith(prefix string) bool {
	t := this
	for _, c := range []byte(prefix) {
		c = c - 'a'
		if t.children[c] != nil {
			t = t.children[c]
		} else {
			return false
		}
	}
	return true
}

/**
 * Your Trie object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Insert(word);
 * param_2 := obj.Search(word);
 * param_3 := obj.StartsWith(prefix);
 */
