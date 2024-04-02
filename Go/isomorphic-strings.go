func isIsomorphic(s string, t string) bool {
    s2t := map[byte]byte{}
    t2s := map[byte]byte{}
    for i := range []byte(s) {
        sx, sok := s2t[s[i]]
        tx, tok := t2s[t[i]]
        if sok && tok && sx == t[i] && tx == s[i] {
            continue
        } else if !sok && !tok {
            s2t[s[i]] = t[i]
            t2s[t[i]] = s[i]
        } else {
            return false
        }
    }
    return true
}