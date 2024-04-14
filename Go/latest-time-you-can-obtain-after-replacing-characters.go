func findLatestTime(s string) string {
    t := []byte(s)
    if s[0] == '?' {
        if s[1] == '?' || s[1] == '0' || s[1] == '1' {
            t[0] = '1'            
        } else {
            t[0] = '0'
        }
    }
    if s[0] == '0' && s[1] == '?' {
        t[1] = '9'
    } else if s[1] == '?' {
        t[1] = '1'
    }
    if s[3] == '?' {
        t[3] = '5'
    }
    if s[4] == '?' {
        t[4] = '9'
    }
    return string(t)
}