func rangeSum(nums []int, n int, left int, right int) int {
    temp := make([]int, 0, n * (n + 1) / 2)
    for i := range nums {
        sum := 0
        for _, n := range nums[i:] {
            sum += n
            temp = append(temp, sum)
        }
    }
    slices.Sort(temp)
    // fmt.Println(temp)
    temp = temp[left-1:right]
    // fmt.Println(temp)
    ans := 0
    for _, n := range temp  {
        ans = (ans + n) % 1000000007
    }
    return ans
}