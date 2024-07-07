func numWaterBottles(numBottles int, numExchange int) int {
	drunk := 0
	empty := 0
	for numBottles > 0 {
		drunk += numBottles
		empty += numBottles
		numBottles = 0
		if empty >= numExchange {
			numBottles += empty / numExchange
			empty %= numExchange
		}
	}
	return drunk
}