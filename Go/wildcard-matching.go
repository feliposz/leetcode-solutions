func isMatch(s string, p string) bool {
	match := make([][]bool, len(s) + 1)
    for i := range match {
        match[i] = make([]bool, len(p) + 1)
    }

    // empty s and p always matches
    match[0][0] = true

    // empty s matches with any number of _leading_ '*' on pattern
    for i := 0; i < len(p) && p[i] == '*'; i++ {
        match[0][i+1] = true
    }

    // fill the rest of the table
    for i := 1; i <= len(s); i++ {
        for j := 1; j <= len(p); j++ {
            a, b := s[i-1], p[j-1]
            if b == '*' {
                // start matches any number of chars or zero
                // ...advance 1 on s or advance 1 on p
                match[i][j] = match[i-1][j] || match[i][j-1]
            } else if a == b || b == '?' {
                // current character at s and p match, so use the same truth value of the previous match
                match[i][j] = match[i-1][j-1]
            }
        }
    }
    return match[len(s)][len(p)]
}