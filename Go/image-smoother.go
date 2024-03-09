func imageSmoother(img [][]int) [][]int {
	rows, cols := len(img), len(img[0])
	for i := 0; i < rows; i++ {
		for j := 0; j < cols; j++ {
			count, sum := 0, 0
			for y := -1; y <= 1; y++ {
				i2 := i + y
				for x := -1; x <= 1; x++ {
					j2 := j + x
					if i2 >= 0 && i2 < rows && j2 >= 0 && j2 < cols {
						sum += img[i2][j2] & 255
						count++
					}
				}
			}
			img[i][j] |= (sum / count) << 8
		}
	}
	for i := 0; i < rows; i++ {
		for j := 0; j < cols; j++ {
            img[i][j] >>= 8
        }
    }
	return img
}