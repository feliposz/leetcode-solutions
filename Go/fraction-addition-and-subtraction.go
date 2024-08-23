func fractionAddition(expression string) string {
	pairs := [][2]int{}
	start := 0
	for i := 0; i <= len(expression); i++ {
		if i == 0 && expression[i] == '-' {
			i++
		}
		if i == len(expression) || expression[i] == '-' || expression[i] == '+' {
			parts := strings.Split(expression[start:i], "/")
			num, _ := strconv.Atoi(parts[0])
			den, _ := strconv.Atoi(parts[1])
			pairs = append(pairs, [2]int{num, den})
			start = i
		}
	}
	commonDen := 1
	for _, pair := range pairs {
		commonDen = lcm(commonDen, pair[1])
	}
	num := 0
	for _, pair := range pairs {
		num += pair[0] * commonDen / pair[1]
	}
	div := abs(gcd(num, commonDen))
	num /= div
	commonDen /= div
	return fmt.Sprintf("%d/%d", num, commonDen)
}

func gcd(a, b int) int {
	for b != 0 {
		a, b = b, a % b
	}
	return a
}

func lcm(a, b int) int {
	return a * b / gcd(a, b)
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}