func shortestSubstrings(arr []string) []string {
    ssFirst := make(map[string]int)
    ssLast := make(map[string]int)
    for pos, s := range arr {
        for i := 0; i < len(s); i++ {
            for j := i + 1; j <= len(s); j++ {
                ss := s[i:j]
                if _, ok := ssFirst[ss]; !ok {
                    ssFirst[ss] = pos
                }
                ssLast[ss] = pos
            }
        }
    }
    result := make([]string, len(arr))
    for ss, first := range ssFirst {
        last := ssLast[ss]
        if first == last {
            if result[first] == "" {
                result[first] = ss
            } else if len(ss) < len(result[first]) {
                result[first] = ss
            } else if len(ss) == len(result[first]) && ss < result[first] {
                result[first] = ss
            }
        }
    }
    return result
}