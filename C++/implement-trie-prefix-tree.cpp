class Trie {
    map<char, Trie*> rest;
    bool isWord;
    
public:
    Trie() {
        isWord = false;
    }
    
    void insert(string word) {
        int sz = word.size();
        if (sz > 0) {
            int c = word[0];
            if (rest[c] == nullptr) {
                rest[c] = new Trie();
            }
            if (sz == 1) {
                rest[c]->isWord = true;
            }
            rest[c]->insert(word.substr(1));
        }
    }
    
    bool search(string word) {
        Trie* t = this;
        for (char c: word) {
            if (t->rest[c]) {
                t = t->rest[c];
            } else {
                return false;
            }
        }
        return t->isWord;
    }
    
    bool startsWith(string prefix) {
        Trie* t = this;
        for (char c: prefix) {
            if (t->rest[c]) {
                t = t->rest[c];
            } else {
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */