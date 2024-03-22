func toGoatLatin(sentence string) string {
    words := strings.Split(sentence, " ")
    var a, b strings.Builder
    for i, word := range words {
        a.WriteString("a")
        if i > 0 {
            b.WriteString(" ")
        }
        switch word[0] {
        case 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U':
            b.WriteString(word)
        default:
            b.WriteString(word[1:])
            b.WriteString(word[:1])
        }
        b.WriteString("ma")
        b.WriteString(a.String())
    }
    return b.String()
}