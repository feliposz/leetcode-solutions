func minRemoveToMakeValid(s string) string {
    t := []byte(s)
    leftCount, rightCount := 0, 0
    for i := range t {
        if t[i] == '(' {
            leftCount++
        } else if t[i] == ')' {
            if leftCount > 0 {
                leftCount--
            } else {
                t[i] = ' '
            }
        }
    }
    for i := len(t) - 1; i >= 0; i-- {
        if t[i] == ')' {
            rightCount++
        } else if t[i] == '(' {
            if rightCount > 0 {
                rightCount--
            } else {
                t[i] = ' '
            }
        }
    }

    t = slices.DeleteFunc(t, func (b byte) bool {
        return b == ' '
    })
    return string(t)
}