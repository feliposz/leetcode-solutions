func countOfAtoms(formula string) string {
    m := subcount(formula)
    res := ""
    atoms := []string{}
    for k := range m {
        atoms = append(atoms, k)
    }
    slices.Sort(atoms)
    for _, k := range atoms {
        res += k
        v := m[k]
        if v > 1 {
            res += strconv.Itoa(v)
        }
    }
    return res
}

func subcount(formula string) map[string]int {
    // fmt.Println(formula)
    res := map[string]int{}
    curr := ""
    count := 0
    for i := 0; i < len(formula); i++ {
        c := formula[i]
        if c >= 'A' && c <= 'Z' {
            if curr != "" {
                if count == 0 {
                    count = 1
                }
                res[curr] += count
            }
            curr = string(c)
            count = 0
        } else if c >= 'a' && c <= 'z' {
            curr += string(c)
        } else if c >= '0' && c <= '9' {
            count = count * 10 + int(c - '0')
        } else if c == '(' {
            if curr != "" {
                if count == 0 {
                    count = 1
                }
                res[curr] += count
            }
            curr = ""
            count = 0
            open := 1
            j := i + 1
            for {
                if formula[j] == '(' {
                    open++
                } else if formula[j] == ')' {
                    open--
                    if open == 0 {
                        break
                    }
                }
                j++
            }
            sub := subcount(formula[i+1:j])
            i = j+1
            count = 0
            for i < len(formula) && formula[i] >= '0' && formula[i] <= '9' {
                count = count * 10 + int(formula[i] - '0')
                i++
            }
            if count == 0 {
                count = 1
            }
            for k, v := range sub {
                res[k] += v * count
            }
            count = 0
            curr = ""
            i--
        }
    }
    if curr != "" {
        if count == 0 {
            count = 1
        }
        res[curr] += count
    }
    return res
}