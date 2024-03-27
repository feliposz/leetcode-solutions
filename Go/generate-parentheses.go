func generateParenthesis(n int) []string {
    result := make([]string, 0)
    generate("", 0, n*2, &result)
    return result
}

func generate(prefix string, open, n int, result *[]string) {
    if n == 0 {
        if open == 0 {
            *result = append(*result, prefix)
        }
        return
    }
    generate(prefix + "(", open + 1, n - 1, result)
    if open > 0 {
        generate(prefix + ")", open - 1, n - 1, result)
    }
}