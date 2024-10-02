func minimumRefill(plants []int, capacityA int, capacityB int) int {
	a, b := capacityA, capacityB
	i, j := 0, len(plants)-1
	refills := 0
	for i <= j {
		if i == j {
			if a >= b {
				if a < plants[i] {
					refills++
				}
			} else {
                if b < plants[i] {
					refills++
				}
            }
			break
		}
		if a < plants[i] {
			refills++
			a = capacityA
		}
		a -= plants[i]
		if b < plants[j] {
			refills++
			b = capacityB
		}
		b -= plants[j]
		i++
		j--
	}
	return refills
}