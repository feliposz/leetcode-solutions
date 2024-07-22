func sortPeople(names []string, heights []int) []string {
    people := make([]*person, len(names))
    for i := range names {
        people[i] = &person{names[i], heights[i]}
    }
    slices.SortFunc(people, func (a, b *person) int {
        return b.height - a.height
    })
    ans := make([]string, len(people))
    for i := range people {
        ans[i] = people[i].name
    }
    return ans
}

type person struct {
    name string
    height int
}