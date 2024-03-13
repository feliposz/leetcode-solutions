func pivotInteger(n int) int {
	total := (1 + n) * n / 2
	//left = right
	//right = total - left + x
	//(1 + x) * x / 2 = (1+n)*n/2 - (1+x)*x/2 + x
	//x + x*x = n + n*n - x - x*x + x*2
	//x = sqrt((n + n*n) / 2)
    x := int(math.Sqrt(float64(n + n*n) / 2))
    if x * x == total {
        return x
    }
	return -1
}