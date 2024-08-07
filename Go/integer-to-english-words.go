func numberToWords(num int) string {
	if word, found := n2w[num]; found {
		return word
	}

	result := ""
	billions := num / 1000000000
	if billions > 0 {
		result += " " + numberToWords(billions) + " Billion"
	}
	num %= 1000000000

	millions := num / 1000000
	if millions > 0 {
		result += " " + numberToWords(millions) + " Million"
	}
	num %= 1000000

	thousands := num / 1000
	if thousands > 0 {
		result += " " + numberToWords(thousands) + " Thousand"
	}
	num %= 1000

	cents := num / 100
	if cents > 0 {
		result += " " + numberToWords(cents) + " Hundred"
	}

	tensAndUnits := num % 100
	if tensAndUnits > 0 && tensAndUnits <= 20 {
		result += " " + numberToWords(tensAndUnits)
	} else {
		tens := tensAndUnits / 10
		units := tensAndUnits % 10
		if tens > 0 {
			result += " " + numberToWords(tens*10)
		}
		if units > 0 {
			result += " " + numberToWords(units)
		}
	}

	return result[1:]
}

var n2w = map[int]string{
	0:          "Zero",
	1:          "One",
	2:          "Two",
	3:          "Three",
	4:          "Four",
	5:          "Five",
	6:          "Six",
	7:          "Seven",
	8:          "Eight",
	9:          "Nine",
	10:         "Ten",
	11:         "Eleven",
	12:         "Twelve",
	13:         "Thirteen",
	14:         "Fourteen",
	15:         "Fifteen",
	16:         "Sixteen",
	17:         "Seventeen",
	18:         "Eighteen",
	19:         "Nineteen",
	20:         "Twenty",
	30:         "Thirty",
	40:         "Forty",
	50:         "Fifty",
	60:         "Sixty",
	70:         "Seventy",
	80:         "Eighty",
	90:         "Ninety",
	100:        "One Hundred",
	1000:       "One Thousand",
	1000000:    "One Million",
	1000000000: "One Billion",
}