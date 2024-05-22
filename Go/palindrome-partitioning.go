func partition(s string) [][]string {
    // start with an empty partition
    part := []string{}
    // all valid palindrome partitions generated
    result := [][]string{}
    // start recursion
    genPartitions(s, &part, &result)
    return result
}

func isPalindrome(s string) bool {
    left, right := 0, len(s) - 1
    for left < right {
        if s[left] != s[right] {
            return false
        }
        left++
        right--
    }
    return true
}

func genPartitions(s string, part *[]string, result *[][]string) {
    
    // if s is empty, it means recursion reached the base case 
    // and then "part" is a complete partition of all palindrome substrings
    if s == "" {
        // make a copy of this partition and save it to "result"
        clone := make([]string, len(*part))
        copy(clone, *part)
        *result = append(*result, clone)
        return
    }

    // check every possible subdivision of s
    for i := 1; i <= len(s); i++ {
        // split in two parts
        prefix := s[0:i]
        suffix := s[i:]
        if isPalindrome(prefix) {
            // prefix is a valid palindrome, so add it to current partition and recursively check the rest of "s"
            *part = append(*part, prefix)
            genPartitions(suffix, part, result)
            // pop the prefix from the current partition slice and continue with the next split
            *part = (*part)[:len(*part)-1]
        }
    }
}