func wordBreak(s string, wordDict []string) []string {
    dict := map[string]struct{}{}
    for _, word := range wordDict {
        dict[word] = struct{}{}
    }
    curr := []string{}
    result := []string{}
    breakSentence(s, dict, &curr, &result)
    return result
}

func breakSentence(s string, dict map[string]struct{}, curr *[]string, result *[]string) {
    if len(s) == 0 {
        *result = append(*result, strings.Join(*curr, " "))
        return
    }
    for i := 0; i <= len(s); i++ {
        word := s[:i]
        if _, found := dict[word]; found {
            *curr = append(*curr, word)
            breakSentence(s[i:], dict, curr, result)
            *curr = (*curr)[:len(*curr)-1]
        }
    }
}