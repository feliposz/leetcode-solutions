func reverseParentheses(s string) string {
	stack := []int{}
    sub := []byte(s)
	for i, ch := range s {
		if ch == '(' {
            stack = append(stack, i)
        } else if ch == ')' {
            a, b := stack[len(stack)-1] + 1, i - 1
            stack = stack[:len(stack)-1]
            for a < b {
                sub[a], sub[b] = sub[b], sub[a]
                a++
                b--
            }
        }
	}
    result := []byte{}
	for _, b := range sub {
        if b == '(' || b == ')' {
            continue
        }
		result = append(result, b)
	}
	return string(result)
}