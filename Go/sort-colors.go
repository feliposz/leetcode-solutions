func sortColors(nums []int)  {
    colors := [3]int{}
    for _, n := range nums {
        colors[n]++
    }
    index := 0
    for color, count := range colors {
        for count > 0 {
            nums[index] = color
            count--
            index++
        }        
    }
}