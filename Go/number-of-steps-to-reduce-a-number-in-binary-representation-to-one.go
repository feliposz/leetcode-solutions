func numSteps(s string) int {
	steps := 0
	carry := byte(0)
	b := []byte(s)
	for i := len(b) - 1; i > 0; i-- {
		if (b[i]-'0'+carry)%2 == 1 {
			steps += 2
			carry = 1
		} else {
			steps++
		}
	}
	return steps + int(carry)
}

func SLOW_numSteps(s string) int {
	steps := 0
	b := []byte(s)
	for len(b) > 1 {
		// fmt.Println(s)
		if b[len(b)-1] == '0' {
			b = b[:len(b)-1]
		} else {
			b = incr(b)
		}
		steps++
	}
	return steps
}

func incr(b []byte) []byte {
	carry := byte(1)
	for i := len(b) - 1; i >= 0; i-- {
		b[i] += carry
		if b[i] > '1' {
			b[i] = '0'
			carry = 1
		} else {
			carry = 0
		}
	}
	if carry == 1 {
		b = append([]byte{'1'}, b...)
	}
	for i := 0; i < len(b); i++ {
		if b[i] == '1' {
			return b[i:]
		}
	}
	return b
}