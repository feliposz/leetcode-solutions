func makeEqual(words []string) bool {
    var freq [26]int
    // count the total occurences of each letter
    for _, word := range words {
        for _, c := range word {
            freq[c - 'a']++
        }
    }
    n := len(words)
    for _, count := range freq {
        if count % n != 0 {
            // if any count of occurences is not divisible by the number of strings...
            // then it's impossible to make all strings equal
            return false
        }
    }
    return true
}