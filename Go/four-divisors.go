func sumFourDivisors(nums []int) int {
    sum := 0
    for _, num := range nums {
        x := helper(num)
        //fmt.Printf("num = %d, x = %d\n", num, x)
        sum += x
    }
    return sum
}

func helper(num int) int {
    //fmt.Printf("num = %d\n", num)
    count := 0
    sum := 0
    other := num
    for div := 1; div < other; div++ {
        if num % div == 0 {
            other = num / div
            if other == div {
                count++
                sum += div
            } else {                
                count += 2
                sum += div + other
            }
            //fmt.Printf("div = %d, other = %d\n", div, other)
            if count > 4 {
                return 0
            }
        }
    }
    if count != 4 {
        return 0
    }
    return sum
}