func compareVersion(version1 string, version2 string) int {
    v1s := strings.Split(version1, ".")
    v2s := strings.Split(version2, ".")
    l := max(len(v1s), len(v2s))
    v1 := make([]int, l)
    v2 := make([]int, l)
    for i, s := range v1s {
        v1[i], _ = strconv.Atoi(s)
    }
    for i, s := range v2s {
        v2[i], _ = strconv.Atoi(s)
    }
    for i := 0; i < l; i++ {
        if v1[i] < v2[i] {
            return -1
        } else if v1[i] > v2[i] {
            return 1
        }
    }
    return 0
}